#include <iostream>

std::string format(std::string p1, std::string r1) {
	return p1.replace(p1.find('{'), 2, r1);
}

std::string format(std::string p1, std::string r1, std::string r2) {
	std::string s = p1.replace(p1.find('{'), 2, r1);
	std::string z = s.replace(p1.find('{'), 2, r2);
	return z;
}