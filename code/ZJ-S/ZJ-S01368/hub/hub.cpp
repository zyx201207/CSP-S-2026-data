#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct p{
	ll y,z;
};
ll c,t,n,k,dis[5010][5010],vis[5010];
vector<ll> a[5010];
inline ll read(){
	ll s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void bfs(ll x){
	queue<p> q;
	q.push({x,0});
	memset(vis,0,sizeof(vis));
	vis[x]=1;
	while(!q.empty()){
		p tmp=q.front();
		q.pop();
		dis[x][tmp.y]=tmp.z;
		for(ll i=0;i<a[tmp.y].size();i++){
			ll y=a[tmp.y][i];
			if(vis[y]) continue;
			vis[y]=1;
			q.push({y,tmp.z+1});
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		memset(dis,0x3f,sizeof(dis));
		n=read();k=read();
		for(ll i=1;i<n;i++){
			ll x=read(),y=read();
			a[x].push_back(y);
			a[y].push_back(x);
		}
		for(ll i=1;i<=n;i++){
			bfs(i);
		}
		if(k==2){
			for(ll i=1;i<=n;i++){
				for(ll j=1;j<=n;j++){
					
				}
			}
		}
	}
}
