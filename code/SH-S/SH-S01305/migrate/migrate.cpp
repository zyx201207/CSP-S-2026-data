#include<bits/stdc++.h>
#define int long long
using namespace std;
int useless,t;
int x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> useless >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		if(useless==11 || useless==12){
			int del=x[2]-x[1];
			if(del*2>d){
				cout << 0 << '\n';
				continue;
			}
			int speed=d/del;
			int ans=0;
			for(int i=2;i*speed<=n;i++){
				ans+=n-(i*speed)+1;
			}
			cout << ans << '\n';
		}
	}
}
