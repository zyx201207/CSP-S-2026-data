#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+5,M=2e6+5;
ll c,t,n,d,x[M],dr[M],dis[M],cnt[M],sum[M],h[M],tot,nd[M];
struct Node{
	ll to,nxt;
}edges[N*N];
void ADD(ll u,ll v){
	edges[++tot].to=v;
	edges[tot].nxt=h[u];
	h[u]=tot;
}
void bfs(ll s){
	queue<ll> q;
	dis[s]=0;
	cnt[s]=1;
	q.push(s);
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		for(ll i=h[u];i;i=edges[i].nxt){
			ll v=edges[i].to;
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
			}
			else if(dis[v]==dis[u]+1)cnt[v]+=cnt[u];
		}
	}
}
void Main(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++)cin>>x[i],dr[i]=0;
	ll r=1;
	for(ll i=1;i<=n;i++){
		r=max(r,i);
		while(r<n && x[r+1]-x[i]<=d)r++;
		dr[i]=r;
	}
	if(c>=11 && c<=12){
		// cerr<<1<<'\n';
		for(ll i=1;i<=n;i++)dis[i]=cnt[i]=0,sum[i]=nd[i]=0;
		ll p=dr[1]-1;
		dis[1]=0;
		cnt[1]=1;
		sum[1]=1;
		for(ll i=2;i<=1+p;i++){
			dis[i]=1;
			cnt[i]=1;
			sum[i]=sum[i-1]+cnt[i];
		}
		// cerr<<p<<'\n';
		// cerr<<1<<'\n';
		if(p==0){
			cout<<0<<'\n';
			return ;
		}
		for(ll i=1;i*p+2<=n;i++){
			// if(i<=100)cerr<<i*p+2<<' '<<(i+1)*p+1<<'\n';
			for(ll j=i*p+2;j<=min(n,(i+1)*p+1);j++){
				dis[j]=i+1;
				cnt[j]=sum[i*p+1]-sum[j-p-1];
				sum[j]=sum[j-1]+cnt[j];
				nd[j]=nd[j-1]+(cnt[j]==2);
			}
			// if(cnt[1]!=1){
			// 	cerr<<i<<'\n';
			// 	break;
			// }
		}
		// for(ll i=1;i<=100;i++)cerr<<cnt[i]<<' ';
		// 	cerr<<'\n';
		// cerr<<1<<'\n';
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ans+=nd[i]+nd[n-i+1];
		}
		cout<<ans/2<<'\n';
		return ;
	}
	for(ll i=1;i<=n;i++)h[i]=0;
	tot=0;
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=dr[i];j++)ADD(i,j),ADD(j,i);
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++)dis[j]=-1,cnt[j]=0;
		bfs(i);
		// cout<<i<<'\n';
		// for(ll j=1;j<=n;j++)cout<<dis[j]<<' ';
		// cout<<'\n';
		// for(ll j=1;j<=n;j++)cout<<cnt[j]<<' ';
		// cout<<'\n';
		for(ll j=i+1;j<=n;j++){
			if(cnt[j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)Main();
	return 0;
}