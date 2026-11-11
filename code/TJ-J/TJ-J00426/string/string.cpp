#include<bits/stdc++.h>
using namespace std;
long long n, a, num;
char c;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a >> c;
		for(int j = 1;j<=a;j++){
			s+=char(c);
		}
	}
	//cout << s;
	for(int i = 0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) num++;
	}
	//num = 3000000000;
	cout << num;
	return 0;
}
