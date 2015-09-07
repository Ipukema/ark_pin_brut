#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

#define SPACE_BAR 0x20

void press_keys(char number) {
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	ip.ki.wVk = number;
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.wVk = number;
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
}

int main()
{
	cout << "####################" << endl;
	cout << "ARK PIN Code brutter" << endl;
	cout << "####################" << endl;

	char guess[5] = "0000";
	int guesscounter = 0;
	string deter;

	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	cout << "down or up?" << endl;
	getline(cin, deter);

	if (deter == "down") {
		while (true) {
			if (guesscounter <= 9999) {
				if (!GetAsyncKeyState(SPACE_BAR)) {
					cout << "gueguesscounter:" << guesscounter << endl;
					snprintf(guess, 6, "%04d", guesscounter);

					press_keys('E');
					Sleep(500);
					cout << "1#: " << guess[0] << endl;
					press_keys(guess[0]);
					cout << "2#: " << guess[1] << endl;
					press_keys(guess[1]);
					cout << "3#: " << guess[2] << endl;
					press_keys(guess[2]);
					cout << "4#: " << guess[3] << endl;
					press_keys(guess[3]);
					Sleep(1000);
				}
				else {
					cout << "pressed spacebar exit.." << endl;
					return 0;
				}
			}
			else {
				//cin.get();
				return 0;
			}
			guesscounter++;
		}
	}
	else {
		while (true) {
			guesscounter = 9999;
			for (int big = 0; guesscounter > big; guesscounter--) {
				cout << guesscounter << endl;

				if (!GetAsyncKeyState(SPACE_BAR)) {
					cout << "gueguesscounter:" << guesscounter << endl;
					snprintf(guess, 6, "%04d", guesscounter);

					press_keys('E');
					Sleep(500);
					cout << "1#: " << guess[0] << endl;
					press_keys(guess[0]);
					cout << "2#: " << guess[1] << endl;
					press_keys(guess[1]);
					cout << "3#: " << guess[2] << endl;
					press_keys(guess[2]);
					cout << "4#: " << guess[3] << endl;
					press_keys(guess[3]);
					Sleep(1000);
				}
				else {
					cout << "pressed spacebar exit.." << endl;
					return 0;
				}
			}
			if (guesscounter == 0) {
				//cin.get();
				return 0;
			}
		}
	}
}
