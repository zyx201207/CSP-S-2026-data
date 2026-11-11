#include <bits/stdc++.h>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define system(...) assert(!system(__VA_ARGS__))

const int N = 1e6 + 5;

int cnt;

int main() {
	system("g++ -o hub hub.cpp -O2 -static -std=c++14");
	system("g++ -o gen gen.cpp -O2 -static -std=c++14");
	system("g++ -o bf bf.cpp -O2 -static -std=c++14");
	while (1) {
		system("./gen");
		system("./bf");
		system("./hub");
		system("diff hub.out hub.ans");
		cerr << "AC: " << ++cnt << "\n";
	}
	return 0;
}
