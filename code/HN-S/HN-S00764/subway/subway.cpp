#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,k;
int w[500005];
ll subs[504];
struct str{
	ll a;
	ll t;
}sub[504][504];
ll f(ll now,ll y){
	if (now==y)return 0;
	ll amin=1<<16;
	for(int i=2;i<=subs[now];i++){
		amin=min(amin,f(sub[now][i].a,y)+sub[now][1].t+sub[now][i].t);
	}
	return amin;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		subs[i]=k;
		for(int j=1;j<=k;j++){
			cin>>sub[i][j].a>>sub[i][j].t;
		}
	}
	if (c>=7&&c<=11){
		for(int i=0;i<q;i++){
			ll tot=0;
			ll x,y;
			cin>>x>>y;
			if (x>y)swap(x,y);
			tot+=w[x]+w[y];
			ll now_in=x;
			while(now_in!=y){
				tot+=sub[now_in][1].t+sub[now_in][2].t;
				now_in=sub[now_in][2].a;
			}
			cout<<tot<<'\n';
		}
		return 0;
	}
	for(int i=0;i<q;i++){
		ll tot=0;
		ll x,y;
		cin>>x>>y;
		if (x>y)swap(x,y);
		tot+=w[x]+w[y];
		tot+=f(x,y);
		cout<<tot<<'\n';
	}
	return 0;
} 
