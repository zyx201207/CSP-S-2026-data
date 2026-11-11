#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt,ans; 
char a[1000005],b[1000005],c[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	string s = "";
	for(int i = 1;i <= n;i ++){
		ll x;
		char y;
		cin >> x >> y;
		for(int j = 1;j <= x;j ++){
			a[j] = y;
		}for(int j = x;j >= 1;j --){
			b[j] = y;
		}
		cnt += x;
		
	}
	for(int i = 1;i <= n;i ++){
		c[i] = b[n - i];
	}
	for(int i = 1;i <= cnt / 2;i ++){
		if(a[i]!= c[i]){
			ans ++;
			c[i] = a[i];
			
		}
	}
	cout << ans;
	return 0;
} 
