#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long idn = n;
	long long a;
	char b;
	string s;
	long long cnt = 0;
	cin >> n;
	for(long long i = 0;i <= idn;i++){
		cin >> a >> b  endl;
		s += a * b;
	}
	long long l = 0;
	long long r = s.size() - 1;
	while(l < r){
		if(s[l] != s[r]){
		s[l] = s[r];
		cnt++;
		l++;
		r--;
		}
	}
	cout << cnt;
	

}
