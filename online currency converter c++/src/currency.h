#pragma once
#include <iostream>
class currency {
private:
	int answer;
	int answer2;
	double HowMuch;
	double currencyvalue;
	std::string url;
	std::string finalresult;
	std::string chosencurrency;
	std::string chosencurrency2;
	std::string result;
	std::string listcurrency = "convert from \n1.USD\n2.EUR\n3.IDR\n4.GBP\n5.MYR\n6.CNY\ninsert your input(number only): ";
private:
	void Print(std::string* List);
	void GetUserInput(int* answer, std::string* message);
	void GetUserInput(double* answer, std::string* message);
	void GetChosenCurrency(int* answer, std::string* dest);
	void BuildString();
	void GetCurrencyValue();
	void Calculate();
	void PrintResult();
public:
	currency(std::string url) { this->url = url; }
	void RunLoop();
	void Run();
};
