#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int x=1;
struct edge{
	ll x1;
	ll x2;
	ll w;
	int cnt=1;
}a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int z=1;z<=t;++z){
		memset(a,0,sizeof(a));
		ll n,d,ans,f=0;
		cin>>n>>d;
		for(ll i=1;i<=n;++i) cin>>a[i].x1;
		for(ll i=1;i<=n-1;++i) a[i].x2=a[i+1].x1;
		for(ll i=1;i<=n-1;++i){
			a[i].w=a[i].x2-a[i].x1;
			if(a[i].w>d) a[i].cnt=0;
		}
		for(ll i=2;i<=n-1;++i) if(a[i].w!=a[i-1].w) x=0;
		if(x==0)cout<<"0"<<endl;
		else {
			x=a[1].w;
			for(ll i=1;i<=n-2;++i){
				ll an=n-2*i;
				if(d>=i*x&&d<(i+1)*x&&i!=1&&an>=0){
					ans=an;
					cout<<ans+1<<endl;
					break;
				}
			}
			if(ans<0) cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}