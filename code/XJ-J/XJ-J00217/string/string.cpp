#include<iostream>
#include<cstring>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum91 = 0;
	string ssss;
	cin >> n;
	while(n--) {
		long long xxxx;
		char yyyy;
		cin >> xxxx >> yyyy;
		while(xxxx--) ssss += yyyy;
	}
    long long sy = ssss.size();
	sum91 = ssss.size() / 2;
	long long kfc = sum91;
	for(long long i = 0;i < kfc;i++) {
		if(ssss[i] == ssss[sy - i - 1]) sum91--;
	}
	cout << sum91;
	return 0;
}
