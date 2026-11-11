#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000001];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(x[1]+x[3]==x[2]*2){
			int minu=x[2]-x[1];
			if(d<=minu){
				cout<<0<<'\n';
				continue;
			}
			int maxn=d/minu;
			if(2*maxn>n+1)cout<<0<<'\n';
			else cout<<n-2*maxn+1<<'\n';
		}
		else cout<<0<<'\n';
	}
	return 0;
} 
