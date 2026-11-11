#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=2e6+10;
int c,t,n,vis[maxn];
ll d,a[maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==1){
			cout<<0<<'\n';
			continue;
		} 
			if(d<2*(a[2]-a[1])){
				cout<<0<<'\n';
			}
			else{
				ll k=d/(a[2]-a[1]);
				ll len=k*2;
				cout<<max(0LL,n-len+1)<<'\n';
			}
	}
	return 0;
}
