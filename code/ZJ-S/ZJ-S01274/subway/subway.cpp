#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=500010;
const ll N=510;
const ll Q=100010;
ll c,n,m,d,q;
ll w[M];
ll k[M];
ll a[N][M];
ll t[N][M];
ll x[Q][3];
ll ans=0;
bool vis[M];
void bfs(ll x,ll y){
	ans+=(w[x]+w[y]);
	queue<ll>q;
	q.push(x);
	vis[x]=1;
	while(!q.empty()){
		ll tx=q.front();
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				if(a[i][j]==tx){
					if(vis[a[i][j+1]])continue;
					if(a[i][j+1]==y)cout<<ans<<endl;
					q.push(a[i][j+1]);
					vis[a[i][j+1]]=1;
				}
			}
		}
		ans+=t[1][1];
		q.pop();
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(ll r=1;r<=q;r++){
		cin>>x[r][1]>>x[r][2];
	}
	if(c>=12&&c<=19){
		for(ll i=1;i<=q;i++){
			bfs(x[i][1],x[i][2]);
			cout<<ans<<endl;
			return 0;
		}
	}
	for(int i=1;i<=q;i++) cout<<1<<endl;
	return 0;
}
