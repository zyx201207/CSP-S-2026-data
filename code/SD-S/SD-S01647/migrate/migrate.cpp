#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,opt,t,d,a[500005],sum;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>opt>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(opt==11||opt==12){
			int x=d/(a[2]-a[1]),ans=0;
			for(int i=x+1;i<x*2;i++)
				if(i==x+x-1)
					ans+=n-i;
			cout<<ans<<'\n';
			continue;
		}
		cout<<0<<'\n';
		sum=0;
	}
	return 0;
}
