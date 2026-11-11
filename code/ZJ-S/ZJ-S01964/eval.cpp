#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INF_LL 0x3f3f3f3f3f3f3f3f
using namespace std;

const int N = 4;

string name[4] = {"crystal", "subway", "migrate", "hub"};
int num[4] = {4, 7, 6, 5};

int main() {

	for (int i = 0; i < 4; ++i) {
		cout << "Test " << name[i] << "!\n";
		string st = "cd ~/" + name[i] + " && ";
		string file = "./" + name[i];
		assert(!system((st + "g++ -O2 -static -std=c++14 -o " + file + " " + file + ".cpp").c_str()));
		for (int j = 1; j <= num[i]; ++j) {
			string tf = file + (char)(j + '0');
			assert(!system((st + "cp " + tf + ".in " + file + ".in").c_str()));
			assert(!system((st + file).c_str()));
			assert(!system((st + "diff -Z " + tf + ".ans " + file + ".out").c_str()));
			cout << "Test " << j << " Pass!\n";
		}
	}

	return 0;
}