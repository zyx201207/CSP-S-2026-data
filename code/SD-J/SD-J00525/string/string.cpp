#include<bits/stdc++.h>
using namespace std;
char c[100000002];
void solve(int n,char x[]){
	int len = 0;
	for(int i = 1; i <= n; i++){
		int t;
		char y;
		cin >> t >> y;
		for(int j = 1; j <= t; j++){
			x[len] = y;
			len++;
		}
	}
	long long midp = len/2,ans = 0;
	for(int i = 0; i < midp; i++){
		if(x[i] != x[len-1-i]) ans++;
	}
	cout << ans;
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	solve(n,c);
	return 0;
} 
