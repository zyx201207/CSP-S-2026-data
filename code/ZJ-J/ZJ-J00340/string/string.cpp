#include <iostream>
using namespace std;
int main()
{
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	int n,l;
	cin >> n;
	string s = "";
	char a;
	for(int i = 1;i <= n;i++){
		cin >> l >> a;
		for(int i = 1;i <= l;i++){
			s += a;
		}
	}
	int len = s.size(),cnt = 0;
	int len1 = len / 2;
	for(int i = 0;i <= len1;i++){
		if(s[i] != s[len-i-1]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
