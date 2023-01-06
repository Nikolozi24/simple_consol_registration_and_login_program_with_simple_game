#include <windows.h>
#include <iostream>
#include<fstream>
#include<random>
#include<ctime>
void Simple_Game();
bool isLoggin();
bool StringContainNum(std::string str) {
	std::string::iterator it;
	for (it = str.begin(); it != str.end(); it++)
		if (*it == '0' || *it == '1' || *it == '2' || *it == '3' || *it == '4' || *it == '5' || *it == '6' || *it == '7' || *it == '8' || *it == '9') return true;
	return false;
}
bool checkMail(std::string email) {
	std::string::iterator it;
	for (it = email.begin(); it != email.end(); it++) {
		if (*it == '@') return true;
	}
	return false;
}
int main()
{
	int num;
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 2);
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 10;
	fontex.dwFontSize.X = 22;
	fontex.dwFontSize.Y = 22;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
A:
	std::cout << " XXXXXXXXXXXXXX  Welcome to my Game! XXXXXXXXXXXXXXXXXXXXXXXXX  \n do you want to log in or registration? \n1.log in \n 2.registration:\n your choose:  ";
	std::cin >> num;

	if (num == 1 || num == 2) {
		if (num == 1) {
		B:
			bool status = isLoggin();
			if (!status) {
				char ch;
				std::cout << "\nError:ivalid username or password! \ndo you want to try again or goto main page?\nB.try again \nM.Main)\n";
				std::cin >> ch;
				if (ch == 'M' || ch == 'm')goto A;
				else
					if (ch == 'B' || ch == 'b')goto B;
					else {
						goto A;
					}
			}
			else {
				Simple_Game();
				return 0;
			}
		}
		else {
			std::string username, email, password, rePassword, Y_N;
			std::cout << "\n Welcome to registration page \n Eneter UserName:";
		U:
			std::cin >> username;
			if (!StringContainNum(username)) goto E;
			else {
				std::cout << "\t Eroor: invalid username! name must not contain numbers!\n enter userName Again:";
				goto U;
			}

		E:
			std::cout << "please Enter Email: ";
			std::cin >> email;
			if (checkMail(email))goto P;
			else {
				std::cout << "email must contain '@' ";
				goto E;
			}
		P:
			std::cout << "\nplease Enter password: ";
			std::cin >> password;
			if (!StringContainNum(password) && password.length() > 8) goto R;
			else {
				std::cout << "your password is contain number or length is less than 8\n";
				goto P;
			}
		R:
			std::cout << "please confirm the Password: ";
			std::cin >> rePassword;
			if (rePassword == password) goto L;
			else {
				std::cout << "password Doesn't match! please try again! \n";
				goto R;
			}
		L:
			std::ofstream ofs("registration.txt");
			ofs << "username: " << username << " \npassword: " << password << " \nemail:" << email << std::endl;
			std::fstream myfile;
			myfile.open("data.txt" , std::ios::app);
			if (myfile.is_open()) {
				myfile << username<<"\n";
				myfile << password<<"\n";
				myfile.close();
			}
			std::cout << "congregulation! registration complited Succsessfully! in order to join system use your username: " << username << " and password: " << password << std::endl;
			main();
		}
	}
	else goto A;
}
bool isLoggin() {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string name, password, checkName, checkPass;
	SetConsoleTextAttribute(color, 12);
	std::cout << "please Eneter the username: ";
	std::cin >> name;
	std::cout << "please eneter the password: ";
	std::cin >> password;
	std::ifstream ifs("data.txt");
	while (ifs >> checkName && ifs >> checkPass) {
		ifs >> checkName;
		ifs >> checkPass;
		if (name == checkName && password == checkPass) return true;
	}
	return false;
}
void Simple_Game() {
	srand(time(0));
	int random = rand() % 100, userInput = -10;
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 700;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);

	std::cout << " XXXXXXX  Welocome to my Game  XXXXXXXXXXXXn\n Description: this game is about to guess right number with is randomly generated \n bettwen 0 to 100 \n\n\n\ please eneter the your number";

	while (userInput != random) {
		std::cin >> userInput;
		if (userInput > random) {
			std::cout << "random numb is less than" << userInput << std::endl;
		}
		else
			if (userInput < random) {
				std::cout << "random numb is greater than " << userInput << std::endl;
			}
			else {
				continue;
			}
	}
	std::cout << "congregulation! you are right! generated number was: " << random << "\n";
}

