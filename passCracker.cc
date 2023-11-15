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

    int days = static_cast<int>(seconds / (24 * 3600));
    seconds -= days * (24  3600);

    int hours = static_cast<int>(seconds / 3600);
    seconds -= hours * 3600;

    int minutes = static_cast<int>(seconds / 60);
    seconds -= minutes * 60;

    std::cout << days << " days " << hours << " hours " << minutes << " minutes " << seconds << " seconds" << std::endl;

}