#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e2+5,M=5e5+5,X=5e6+5;
ll c,n,m,d,q;
ll st,dis[X],vis[X];
ll wi[M],a[M],t[M],l[M],r[M],ans[N][N];
ll idx,e[2*X],nx[2*X],w[2*X],h[X];
struct node{
	int x,y;
}s[M];
bool cmp(node a,node b){return a.x<b.x;}
void add(ll a,ll b,ll c){
	e[++idx]=b;
	w[idx]=c;
	nx[idx]=h[a];
	h[a]=idx;
}
void djsk(ll st){
	priority_queue<pair<ll,ll>> q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[st]=0;
	q.push(make_pair(0,st));
	while(!q.empty()){
		ll x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(ll i=h[x];i;i=nx[i]){
			ll y=e[i],z=w[i];
			if(dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
				q.push(make_pair(-dis[y],y));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	d=1000;
	for(ll i=1;i<=m;i++) cin>>wi[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			if(j>1){
				add(a[j-1]+i*d,a[j]+i*d,0);
				add(a[j]+i*d,a[j-1]+i*d,0);
			}
			add(a[j],a[j]+i*d,t[j]);
			add(a[j]+i*d,a[j],t[j]);
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>s[i].x>>s[i].y;
		l[i]=s[i].x;
		r[i]=s[i].y;
	}
	sort(s+1,s+1+q,cmp);
	for(int i=1;i<=q;i++){
		if(s[i].x!=s[i-1].x) djsk(s[i].x);
		ans[s[i].x][s[i].y]=dis[s[i].y]+wi[s[i].x]+wi[s[i].y];
	}
	for(int i=1;i<=q;i++)
		cout<<ans[l[i]][r[i]]<<'\n';
	return 0;
}