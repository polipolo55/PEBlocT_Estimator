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
    string charsetname;
    string fullinfo = "combined_OUT.csv";
    ofstream csvout(fullinfo, std::ios::trunc);
    csvout << "Password, Time, Password Type" << endl;
    for(int i = 0; i < 3; ++i) {
        if(i == 0) {
            input = "all_characters.txt";
            charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            charsetname = "Mixed Characters";
        }
        if(i == 1) {
            input = "lowercase.txt";
            charset = "abcdefghijklmnopqrstuvwxyz";
            charsetname = "Lowercase Only";           
        }
        if(i == 2) {
            input = "numbers.txt";
            charset = "0123456789";
            charsetname = "Numbers Only";
        }
        fstream stream(input);
        ofstream txtout(numoutput, std::ios::trunc);
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
            csvout << password << ", " << std::fixed  << std::setprecision(5) << seconds << ", " << charsetname << endl;
        }
        txtout.close();
        stream.close();
    }
    csvout.close();

}