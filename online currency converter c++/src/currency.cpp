#include <iostream>
#include <string>
#include "../dependencies/HTTPRequest.hpp"
#include "currency.h"
double ans;
bool t = false;
std::string errormsg = "Enter valid option : ";
std::string errormsg2 = "enter valid num : ";
std::string msg = "enter the amount you want to convert : ";
std::string listcurrency2;
std::string format(std::string p1, std::string r1);
std::string format(std::string p1, std::string r1, std::string r2);

void currency::RunLoop() {
	while (true) {
		currency::Print(&this->listcurrency);
		currency::GetUserInput(&this->answer, &errormsg);
		currency::GetChosenCurrency(&this->answer, &this->chosencurrency);
		system("cls");
		currency::Print(&listcurrency2);
		currency::GetUserInput(&this->answer2, &errormsg);
		currency::GetChosenCurrency(&this->answer2, &this->chosencurrency2);
		currency::BuildString();
		currency::GetCurrencyValue();
		currency::Print(&msg);
		currency::GetUserInput(&this->HowMuch, &errormsg2);
		currency::Calculate();
		currency::PrintResult();
		std::cin.ignore(256, '\n');
		system("cls");
		t = false;
	}
}

void currency::Run() {
	currency::Print(&this->listcurrency);
	currency::GetUserInput(&this->answer, &errormsg);
	currency::GetChosenCurrency(&this->answer, &this->chosencurrency);
	system("cls");
	currency::Print(&listcurrency2);
	currency::GetUserInput(&this->answer2, &errormsg);
	currency::GetChosenCurrency(&this->answer2, &this->chosencurrency2);
	currency::BuildString();
	currency::GetCurrencyValue();
	currency::Print(&msg);
	currency::GetUserInput(&this->HowMuch, &errormsg2);
	currency::Calculate();
	currency::PrintResult();
	std::cout << "\npress enter to exit...";
	std::cin.ignore(256, '\n');
	std::cin.get();
}

void currency::Print(std::string* list) {
	std::cout << (*list);
}

void currency::GetUserInput(int* answer, std::string* message) {
	std::cin >> (*answer);
	while (std::cin.fail()) {
		std::cin.clear();
		std::cout << *message;
		std::cin.ignore(256, '\n');
		std::cin >> (*answer);
	}
	
	if ((*answer) > 6 || (*answer) < 0) {
		(*answer) = 1;
	}
	if (this->answer == this->answer2) {
		this->answer2 = this->answer + 1;
	}
}

void currency::GetUserInput(double* answer, std::string* message) {
	while (true) {
		try {
			std::string placeholder;
			std::getline(std::cin, placeholder);
			*answer = std::stod(placeholder,NULL);
			ans = *answer;
			break;
		}
		catch (const std::exception& e) {
			if (t) {
				std::cout << *message;
			}
			else { t = true; }
			continue;
		}
	}
	if ((*answer) > 6 || (*answer) < 0) {
		(*answer) = 1;
	}
	if (this->answer == this->answer2) {
		this->answer2 = this->answer + 1;
	}
}

void currency::GetChosenCurrency(int* answer, std::string* dest) {
	std::string list[6] = { "USD","EUR","IDR","GBP","MYR","CNY" };
	int g = *answer - 1;
	std::string formatted = format(std::string("converting from {} to: \n1.USD\n2.EUR\n3.IDR\n4.GBP\n5.MYR\n6.CNY\ninsert your input(number only): "), list[g]);
	*dest = list[g];
	listcurrency2 = formatted;
}
void currency::BuildString() {
	result = format("{}_{}", this->chosencurrency, this->chosencurrency2);
}

void currency::GetCurrencyValue() {//https://free.currconv.com/api/v7/convert?q=USD_PHP&compact=ultra&apiKey=9d53a8bd15d3228bfd71
	std::cout << "getting currency value..." << '\n';
	std::string url = format(this->url, result);
	http::Request req{ url };
	const auto value = req.send("GET"); 
	std::string h = std::string(value.body.begin(), value.body.end());
	this->currencyvalue = strtof(h.substr((h.find(":") + 1), (h.length() - 1)).c_str(), NULL);
}

void currency::Calculate() {
	this->finalresult = std::to_string(ans*this->currencyvalue);
}

void currency::PrintResult() {
	std::cout << finalresult << " " << this->chosencurrency2 ;
}