#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=505,M=5e5+5;
ll dis[N][N],ww[N],ans,a[N];
struct node{
	ll next,to;ll w;
}s[M*21];
ll h[M],cnt;
ll n,m,d,q;
void add(ll x,ll y,ll z){
	s[++cnt].to=y;s[cnt].w=z;
	ll t=h[x];
	h[x]=cnt;
	s[cnt].next=t;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>ww[i];a[i]=ww[i];
	}
//	cout<<ww[520]<<'\n';
//	cout<<'\n';
	for(ll i=1;i<=n;i++){
//		cout<<ww[520]<<' ';
		ll x;cin>>x;
		for(ll j=1;j<=x;j++){
//			cout<<j<<',';
			ll y;ll z;cin>>y>>z;
//			cout<<ww[520]<<','<<y<<','<<z<<','<<cnt<<' ';
			add(y,i,z);
		}
//		cout<<ww[520]<<' ';
		for(ll j=1;j<=n;j++)
			dis[j][i]=1e17;
//		cout<<ww[520]<<'\n';
	}
//	cout<<a[520]<<'\n';
	for(ll i=1;i<=m;i++){
//		cout<<i<<':';
		for(ll j=h[i];j;j=s[j].next)
			for(ll k=h[i];k;k=s[k].next){
				if(k==j)continue;
				dis[s[k].to][s[j].to]=dis[s[j].to][s[k].to]=min(dis[s[j].to][s[k].to],s[j].w+s[k].w);
			}
//		cout<<'\n';
	}
	for(ll i=1;i<=n;i++)dis[i][i]=0;
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++){
				dis[i][j]=dis[j][i]=min(dis[j][i],dis[i][k]+dis[k][j]);
			}
//	cout<<520<<' '<<ww[520]<<'\n';
	for(ll i=1;i<=q;i++){
		ll x,y;cin>>x>>y;
//		cout<<x<<'\n';
		ans=1e17;
		for(ll j=h[x];j;j=s[j].next)
			for(ll k=h[y];k;k=s[k].next){
				ans=min(ans,s[k].w+s[j].w+dis[s[j].to][s[k].to]+ww[x]+ww[y]);
//				cout<<dis[s[j].to][s[k].to]<<' '<<s[k].w<<','<<s[j].w<<' '<<ww[x]<<'&'<<ww[y]<<' ';
			}
//		cout<<'\n';
		cout<<ans<<'\n';
	}
	return 0;
}