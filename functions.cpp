#include "functions.h"

std::map<std::string, std::vector<int>> wordReferences(const std::string& text) {
    std::map<std::string, std::vector<int>> refs;
    std::istringstream stream(text);
    std::string line;
    int line_number = 1;

    std::regex word_regex(R"(\b([a-zA-Z]+)\b)");

    while (getline(stream, line)) {
        std::sregex_iterator words_begin = std::sregex_iterator(line.begin(), line.end(), word_regex);
        std::sregex_iterator words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::string word = (*i).str();
            std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c); });
            refs[word].push_back(line_number);
        }
        line_number++;
    }
    return refs;
}

void findURLs(const std::string& text, const std::function<void(const std::string&)>& callback) {
    const std::regex url_pattern(R"((https?://[^\s]+))");
    std::smatch url_match;
    std::string::const_iterator searchStart(text.cbegin());

    while (std::regex_search(searchStart, text.cend(), url_match, url_pattern)) {
        callback(url_match[0].str());
        searchStart = url_match.suffix().first;
    }
}


void printWordReferences(const std::string& text) {
    auto wordRefs = wordReferences(text);
    std::cout << "+--------------------+----------+--------------------------------------------------+\n";
    std::cout << "| Zodis              | Kartai   | Eilutes                                           \n";
    std::cout << "+--------------------+----------+--------------------------------------------------+\n";
    for (const auto& pair : wordRefs) {
        if (pair.second.size() > 1) {
            std::cout << "| " << std::left << std::setw(18) << pair.first << " | " << std::setw(8) << pair.second.size() << " | ";
            int count = 0;
            for (int line : pair.second) {
                if (count > 0 && count % 10 == 0) std::cout << "\n" << "| " << std::setw(18) << " " << " | " << std::setw(8) << " " << " | ";
                std::cout << line << " ";
                count++;
            }
            std::cout << "\n+--------------------+----------+--------------------------------------------------+\n";
        }
    }
}






void printURLs(const std::string& text) {
    std::cout << "\nRasti URL:\n";
    bool found = false;
    findURLs(text, [&found](const std::string& url) {
        std::cout << url << "\n";
        found = true;
    });
    if (!found) {
        std::cout << "-\n";
    }
    std::cout << "\n";
}


void saveResults(int choice, const std::string& text) {
    std::string filename;
    switch (choice) {
        case 1:
            filename = "Pasikartojantys_Zodziai.txt";
            break;
        case 2:
            filename = "Nuorodos.txt";
            break;
        case 3:
            filename = "Zodziai_ir_Nuorodos.txt";
            break;
    }
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        std::streambuf *coutbuf = std::cout.rdbuf();
        std::cout.rdbuf(outFile.rdbuf());

        if (choice == 1 || choice == 3) {
            printWordReferences(text);
        }
        if (choice == 2 || choice == 3) {
            printURLs(text);
        }

        std::cout.rdbuf(coutbuf);
        outFile.close();
        std::cout << "Rezultatai issaugoti faile " << filename << std::endl;
    } else {
        std::cout << "Nepavyko atidaryti failo rasymui.\n";
    }
}
