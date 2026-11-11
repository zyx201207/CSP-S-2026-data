#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a, n;
string s, c;
long long isp(string s){
	int sum = 0;
	for (int i = 0;i < s.size()/2;i++)
		if (s[i] != s[s.size()-i-1]) sum++;
	return sum;
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a >> c;
		for (int j = 1;j <= a;j++) s += c;
	}
	int k_s = isp(s);
	cout << k_s << '\n';
	return 0;
} 
