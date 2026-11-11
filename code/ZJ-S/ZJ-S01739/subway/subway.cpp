#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll ma=5e5+5;
ll c,n,m,dd,q,w[ma],mi=1e7;
struct sub{
	ll x,xt,y,yt;
}su[1005];
vector<ll> d[ma];
inline ll read(){
	ll x=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
void dfs(ll e,ll nd,ll ld,ll v,ll dep){
	if(nd==e){
		mi=min(v,mi);
		return;
	}
	if(v>=mi||ld==nd||dep>m){
		return;
	}
	for(int i=0;i<d[nd].size();i++){
		sub t=su[d[nd][i]];
		v+=(t.xt+t.yt);
		//cout<<t.y<<endl;
		dfs(e, t.y , t.x, v,dep+1);
		v-=(t.xt+t.yt);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cout<<mi<<endl;
	c=read();
	n=read();
	m=read();
	dd=read();
	q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	ll cnt=0;
	for(int i=1;i<=n;i++){
		ll x,xt,y,yt,k;
		k=read();
		x=read();
		xt=read();
		y=read();
		yt=read();
		su[++cnt].x=x;
		su[cnt].xt=xt;
		su[cnt].y=y;
		su[cnt].yt=yt;
		d[x].push_back(cnt);
		//cout<<su[cnt].x<<" "<<su[cnt].y<<endl;
		su[++cnt].x=y;
		su[cnt].xt=yt;
		su[cnt].y=x;
		su[cnt].yt=xt;
		d[y].push_back(cnt);
		//cout<<su[cnt].x<<" "<<su[cnt].y<<endl;
	}
	for(int i=1;i<=q;i++){
		mi=1e7;
		ll a,b;
		a=read();
		b=read();
		dfs(b,a,0,w[a]+w[b],1);
		printf("%lld\n",mi);
	}
	return 0;
}

