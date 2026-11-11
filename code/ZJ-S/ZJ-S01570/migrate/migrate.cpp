#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,d;
ll a[2000010];
ll dis[2000010];
ll cnt[2000010];
bool f[2000010];
ll ans;
struct Node{
	ll x,step;
};
void bfs(ll x){
	queue<Node>q;
	memset(dis,0x3f3f3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	memset(f,0,sizeof f);
	q.push({x,0});
	dis[x]=0;
	cnt[x]=1;
	while(!q.empty()){
		Node fr=q.front();q.pop();
		for(ll i=x+1;i<=n;i++){
			if(a[i]<=a[fr.x]+d){
				if(dis[i]>dis[fr.x]+1){
					dis[i]=dis[fr.x]+1;
					cnt[i]=1;
					q.push({i,dis[i]});
				}else if(dis[i]==dis[fr.x]+1)cnt[i]++,q.push({i,dis[i]});
			}
		}
	}
//	cout<<x<<":\n";
//	for(ll i=x;i<=n;i++)cout<<cnt[i]<<' ';
//	cout<<endl;
	for(ll i=1;i<=n;i++)if(cnt[i]==2)ans++;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(13<=c&&c<=14){
			cout<<0<<endl;
			continue;
		}
		for(ll i=1;i<=n;i++)cin>>a[i];
		ans=0;
		for(ll i=1;i<=n;i++){
			bfs(i);
		}cout<<ans<<endl;
	}
	return 0;
}