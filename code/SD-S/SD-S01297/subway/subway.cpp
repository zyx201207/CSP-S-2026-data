#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500010];
ll cc[1314];
struct E{
	ll e[2121],x,ee[2121];
}cc[1314];
ll ans[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	ll c,n,m,d,q,ss,sss,ans=0,l,r;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>cc[i].x;
		for(int j=1;j<=cc[i].x;j++){
			cin>>ss>>sss;
			c[i].e[j]=ss;
			ans[ss]=sss;
			c[i].ee[j]=sss;
		}
	}
	while(q--){
		cin>>l>>r;
		cout<<a[l]+a[r]+ans[l]+ans[r]<<endl;
	}
	return 0;
}

