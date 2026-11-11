#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn=1000009;
const ll inf=1e18;
ll Cid,NT,n,k;
vector<ll> es[maxn];
ll dst[maxn];
ll f[maxn],cnt[maxn];
ll find(ll x){return (x==f[x]?x:f[x]=find(f[x]));}
void merge(ll x,ll y){
	x=find(x);y=find(y);
	f[x]=y;
}
void solveBF(){
	ll ans=inf;
	queue<ll> q;
	rep(p,0,(1<<n)-1){
		ll cntk=0;
		rep(i,1,n)	cnt[i]=0,f[i]=i;
		rep(i,1,n)
			if((1<<i-1)&p)cntk++,dst[i]=0;
			else dst[i]=-1;
		if(cntk!=k)	continue;
		while(!q.empty())q.pop();
		rep(i,1,n)	if(dst[i]==0){
			q.push(i);
//			cout<<i<<' ';
			for(ll v:es[i])	if(dst[v]==0){
				merge(v,i);
			}
		}
		rep(i,1,n)	if(dst[i]==0)	cnt[find(i)]++;
		ll cntf=0;
		rep(i,1,n)	if(cnt[i])	cntf++;
		if(cntf>2)	continue;
//		cout<<'\n';
		while(!q.empty()){
			ll u=q.front();
//			cout<<u<<' '<<dst[u]<<'\n';
			q.pop();
			for(ll v:es[u]){
				if(dst[v]!=-1)	continue;
				dst[v]=dst[u]+1;
				q.push(v);
			}
		}
		ll res=*max_element(dst+1,dst+1+n);
//		cout<<res<<'\n';
		ans=min(ans,res);
//		if(res==1){
//			rep(i,1,n)	cout<<i<<' '<<dst[i]<<'\n';
//		}
	}
	cout<<ans<<'\n';
//	cout<<'\n';
}
void solveA(){
	ll m=n/2;
	if(k==n)	cout<<0;
	if(k>=m)	cout<<1<<'\n';
	else cout<<(m-k+3)/4+1;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>Cid>>NT;
	while(NT-->0){
		cin>>n>>k;
		rep(i,1,n)	es[i].clear();
		rep(i,2,n){
			ll u,v;
			cin>>u>>v;
			es[u].push_back(v);
			es[v].push_back(u);
		}
		if(Cid<=3)	solveBF();
		else if(Cid>=13&&Cid<=14)	solveA();
	}
	return 0;
}
