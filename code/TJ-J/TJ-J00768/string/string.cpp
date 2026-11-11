#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	//如果需要调试请注释
	//如果需要提交请删掉注释 
	int n;
	string s = "";
	cin >> n;
	while (n --){
		int num;
		string strr;
		cin >> num >> strr;
		while (num --) s += strr;
	}
	
	int cnt = 0 , sizee = s.size();
	for (int i = 0; i < sizee / 2; i ++){
		if (s[i] != s[sizee - i - 1]) cnt ++;
		else continue;
	}
	cout << cnt;
	//完结撒花 
	return 0;
}
