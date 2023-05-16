//
//  main.cpp
//  kody
//
//  Created by Marek Wala on 16/05/2023.
//

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <algorithm>
using namespace std;

//Ta funkcja sprawdza, czy podany ciąg binarny reprezentuje potęgę 2. Robi to, sprawdzając, czy ciąg pasuje do określonego wzorca - a mianowicie czy zaczyna się od '1' i jest segementowany tylko przez '0'
//
//wyrażenie regularne ^10*$ ma następujące znaczenia:
//
//^ oznacza początek linii.
//1 oznacza, że oczekiwane jest dokładnie jedno wystąpienie znaku '1'
//0* oznacza, że oczekuje się zero lub więcej wystąpień znaku '0'
//$ oznacza koniec linii.
//zatem całe wyrażenie oznacza, że oczekiwany ciąg zaczyna się od '1', po którym następuje dowolna liczba '0' (lub brak '0'), a następnie ciąg kończy się
//
//Wszystkie potęgi 2 w systemie binarnym będą pasowały do tego wzorca. Na przykład:
//
//2^0 = 1
//2^1 = 10

//zadanie pierwsze
bool isPowerOfTwo(const string &binaryNumber) {
    regex pattern("^10*$");
    return regex_match(binaryNumber, pattern);
}

//zadanie drugie
bool isValidIP(const string &ip) {
    regex pattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    return regex_match(ip, pattern);
}
//zadanie trzecie
void printFileWithLineNumbers(const string &filename) {
    ifstream file(filename);
    string line;
    int lineNumber = 1;
    while (getline(file, line)) {
        cout<<lineNumber<<": "<<line<<endl;
        lineNumber++;
    }
}

//zadanie czwarte
string insertSpaceAfterPunctuation(const string &input) {
    string output = input;
    for (int i = output.length() - 1; i > 0; i--) {
        if ((output[i] == '.' || output[i] == ',') && output[i + 1] != ' ') {
            output.insert(i + 1, " ");
        }
    }
    return output;
}

int main(int argc, const char * argv[]) {

    int wybierz;

    while (true) {
    cout << endl;
    cout << "Wybierz zadanie" << endl;
    cout << "1. Sprawdzanie wyrazenia ktore odpowiada potedze 2 w zapisie binarnym:" << endl;
    cout << "2. Sprawdzanie poprawnosci adresu ip:" << endl;
    cout << "3. Wypisywanie numeru linii z pliku wejsciowego" << endl;
    cout << "4. Wstawianie odstepu po kazdej kropce lub przecinku" << endl;
    cout << "0. Wyjscie" << endl;
    cout << endl;
    cin>>wybierz;

    string test1,test2,testString2;

    switch (wybierz) {

    case 0:
    return 0;

    case 1:
    // Test funkcji isPowerOfTwo
    cout<<"Test isPowerOfTwo():\n";
    cout<<"Should be true: "<<isPowerOfTwo("100")<<"\n"; // 2^2 = 4
    cout<<"Should be false: "<<isPowerOfTwo("101")<<"\n"; // not a power of 2
    cout<<"Should be true: "<<isPowerOfTwo("1000")<<"\n"; // 2^3 = 8
    cout<<"Wpisz testowy ciag:"<<endl;
    cin>>test1;
    cout<<"Your test:  "<<isPowerOfTwo(test1)<<"\n";
    cout<<"\n";
    break;

    case 2:
    // Test funkcji isValidIP
    cout<<"Test isValidIP():\n";
    cout<<"Should be true: "<<isValidIP("192.168.0.1")<<"\n"; // valid IP
    cout<<"Should be false: "<<isValidIP("256.168.0.1")<<"\n"; // invalid IP (256)
    cout<<"Should be false: "<<isValidIP("192.168.0.")<<"\n"; // invalid IP (missing last octet)
    cout<<"Wpisz testowy ciag:"<<endl;
    cin>>test2;
    cout<<"Your test:  "<<isValidIP(test2)<<"\n";
    cout<<"\n";
    break;

    case 3:
    // Wywołanie funkcji printFileWithLineNumbers
    // Uwaga: upewnij się, że plik o podanej nazwie istnieje w tym samym katalogu co twój program
    cout<<"Test printFileWithLineNumbers():\n";
    printFileWithLineNumbers("test.txt");
    cout<<"\n";
    break;

    case 4:
     // Test funkcji insertSpaceAfterPunctuation
    cout<<"Test insertSpaceAfterPunctuation():\n";
    string testString = "Ciebie,witam.Abemus,papam.";
    cout<<"Before: "<<testString<<"\n";
    cout<<"After: "<<insertSpaceAfterPunctuation(testString)<<"\n";
    // Test na wlasnym stringu
    cout<<"Test insertSpaceAfterPunctuation() write your test string:\n";
    cin>>testString2;
    cout<<"Before: "<<testString2<<"\n";
    cout<<"After: "<<insertSpaceAfterPunctuation(testString2)<<"\n";
    cout<<"\n";
    break;


    }
}
}
