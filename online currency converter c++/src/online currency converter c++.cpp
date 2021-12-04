#include <iostream>
#include <string>
#include "currency.h"
int main()
{
	try {
		currency cur("http://free.currconv.com/api/v7/convert?q={}&compact=ultra&apiKey=<YourApiKey>");
		cur.RunLoop();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}