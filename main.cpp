#include "functions.h"


int main() {
    std::string text;
    std::string input;
    do {
        std::cout << "Ar norite nuskaityti teksta is failo? (t/n): ";
        std::cin >> input;
        if (input == "t") {
            std::cout << "Iveskite failo pavadinima: ";
            std::string filename;
            std::cin >> filename;
            std::ifstream file(filename);
            if (!file.is_open()) {
                file.open("C:\\Users\\nagli\\OneDrive\\Desktop\\Egzamino_Uzduotis\\" + filename);
            }
            if (file.is_open()) {
                std::string line;
                while (getline(file, line)) {
                    text += line + "\n";
                }
                file.close();
            } else {
                std::cout << "Nepavyko atidaryti failo: " << strerror(errno) << "\n";
                return 1;
            }
        } else {
            std::cout << "Iveskite teksta: ";
            std::cin.ignore();
            std::getline(std::cin, text);
        }

        std::cout << "Pasirinkite operacija:\n";
        std::cout << "1) Rasti pasikartojancius zodzius\n";
        std::cout << "2) Isgauti URL\n";
        std::cout << "3) Atlikti abu veiksmus\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                printWordReferences(text);
                break;
            case 2:
                printURLs(text);
                break;
            case 3:
                printWordReferences(text);
                printURLs(text);
                break;
            default:
                std::cout << "Neteisingas pasirinkimas.\n";
                return 1;
        }

        std::cout << "Ar norite issaugoti rezultatus i faila? (t/n): ";
        std::cin >> input;
        if (input == "t") {
            saveResults(choice, text);
        }

        std::cout << "Ar norite vykdyti programa dar karta? (t/n): ";
        std::cin >> input;
    } while (input == "t");

    std::cout << "Spauskite bet kuri mygtuka norint iseiti...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
