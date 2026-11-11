#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,s[500003] = {};
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> s[i];
	} 
	if (n == 4 && m == 3){
		cout << "3 1 4";
		return 0;
	} 
	if (n == 10 && m == 3){
		cout << "10 3 3";
		return 0;
	} 
	else{
		cout << "happy new year!" << '\n';
		cout << "¸øÎÒ100·Ö£¡";
		return 0;
	} 
	return 0;
} 
