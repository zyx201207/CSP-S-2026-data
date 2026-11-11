#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500010];
ll cc[1314];
struct E{
	ll e[2121],x,ee[2121];
}cc[1314];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	ll c,n,m,d,q,ss,sss,ans=0,l,r;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>cc[i].x;
		for(int j=1;j<=2*cc[i];j++){
			cin>>ss>>sss;
			c[i].e[j]=ss;
			c[i].ee[j]=sss;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<i<<endl;
	}
	return 0;
}

