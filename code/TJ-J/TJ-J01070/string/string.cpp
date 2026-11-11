#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string h = "";
	int n;
	cin >>n;
	for(int i = 1 ;i <= n ;i++) {
		long long s; 
		char z;
		cin >> s >> z;
		for(int j = 1;j <= s;j++) {
			h += z;
		}
	}
	long long fs = h.size();
	long long cnt = 0;
	for(int i = 0 ;i * 2 < fs;i++) {
		if(h[i] != h[fs - i - 1]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0; 
}
