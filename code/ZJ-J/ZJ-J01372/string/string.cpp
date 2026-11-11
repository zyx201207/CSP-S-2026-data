#include<bits/stdc++.h>
using namespace std;
int N = 2e5 + 10;
string s;
int n;
long long ans, sum;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	for(int i = 1 ; i <= n ; i++){
		string b;
		int a;
		cin >> a >> b;
		for(int i = 1 ; i <= a ; i++)s += b;
		sum += a;
	}
	
	for(int i = 0 ; i <= (sum - 1) / 2 ; i++)if(s[i] != s[sum - i - 1])ans++;
	
	cout << ans;
	return 0;
}
