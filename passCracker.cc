#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;



int main() {
    string password;
    cin >> password;
    double ta = 0;
    double attspeed = 1000000;
    
    string charset = "abcdefghijklmnopqrstuvwxyz0123456789";
    int setsize = charset.size();
    for(int i = 1; i < password.size(); ++i) {
        ta += pow(setsize, i);
    }
    for(int i = password.size() - 1; i > 0; --i) {
        ta += pow(setsize, i) * charset.find(password[i]);
    }
    double seconds = ta / attspeed;

    std::cout << seconds << std::endl;

}