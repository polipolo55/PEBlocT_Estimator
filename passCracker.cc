#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {

    string password;
    string input;
    string numoutput;
    string csvoutput;
    string charset;
    for(int i = 0; i < 3; ++i) {
        if(i == 0) {
            input = "all_characters.txt";
            numoutput = "all_characters_DATA.txt";
            csvoutput = "all_characters_OUT.csv";
            charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        }
        if(i == 1) {
            input = "lowercase.txt";
            numoutput = "lowercase_DATA.txt";
            csvoutput = "lowercase_OUT.csv";
            charset = "abcdefghijklmnopqrstuvwxyz";           
        }
        if(i == 2) {
            input = "numbers.txt";
            numoutput = "numbers_DATA.txt";
            csvoutput = "numbers_OUT.csv";
            charset = "0123456789";
        }
        fstream stream(input);
        ofstream txtout(numoutput, std::ios::trunc);
        ofstream csvout(csvoutput, std::ios::trunc);
        csvout << "Password, Time" << endl;

        while(stream >> password) {
            double ta = 0;
            double attspeed = 1000000;
            
            int setsize = charset.size();
            for(int i = 1; i < password.size(); ++i) {
                ta += pow(setsize, i);
            }
            for(int i = password.size() - 1; i > 0; --i) {
                ta += pow(setsize, i) * charset.find(password[i]);
            }
            double seconds = ta / attspeed;

            txtout << std::fixed  << std::setprecision(3) << seconds  << endl;
            csvout << password << ", " << std::fixed  << std::setprecision(3) << seconds  << endl;
        }
        txtout.close();
        csvout.close();
        stream.close();
    }

}