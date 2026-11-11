#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct p{
	ll y,z;
	bool operator>(const p &B) const{
		return z>B.z;
	}
};
ll c,n,m,d,Q,w[1000010],k[510],cnt,dis[1000010],vis[1000010];
vector<p> a[1000010];
map<pair<ll,ll>,ll> mp;
priority_queue<p,vector<p>,greater<p> > q;
inline ll read(){
	ll s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();Q=read();
	for(ll i=1;i<=m;i++) w[i]=read();
	cnt=m;
	if(n<=50){
		for(ll i=1;i<=n;i++){
			k[i]=read();
			for(ll j=1;j<=k[i];j++){
				ll y=read(),z=read();
				a[++cnt].push_back({y,z});
				a[y].push_back({cnt,z});
				if(j>1) a[cnt-1].push_back({cnt,0}),a[cnt].push_back({cnt-1,0});
			}
		}
		while(Q--){
			ll x=read(),y=read();
			memset(dis,0x3f,sizeof(dis));
			dis[x]=0;
			memset(vis,0,sizeof(vis));
			q.push({x,0});
			while(!q.empty()){
				ll X=q.top().y;
				q.pop();
				if(vis[X]) continue;
				vis[X]=1;
				for(ll i=0;i<a[X].size();i++){
					ll Y=a[X][i].y,z=a[X][i].z;
					if(dis[X]+z<dis[Y]) dis[Y]=dis[X]+z,q.push({Y,dis[Y]});
				}
			}
	//		cout<<dis[y]<<"\n";
			printf("%lld\n",dis[y]+w[x]+w[y]);
		}
	}
	else{
		for(ll i=1;i<=n;i++){
			k[i]=read();
			for(ll j=1;j<=k[i];j++){
				ll y=read(),z=read();
				a[m+i].push_back({y,z});
				a[y].push_back({m+i,z});
			}
		}
		while(Q--){
			ll x=read(),y=read();
			memset(dis,0x3f,sizeof(dis));
			dis[x]=0;
			memset(vis,0,sizeof(vis));
			q.push({x,0});
			while(!q.empty()){
				ll X=q.top().y;
				q.pop();
				if(vis[X]) continue;
				vis[X]=1;
				for(ll i=0;i<a[X].size();i++){
					ll Y=a[X][i].y,z=a[X][i].z;
					if(dis[X]+z<dis[Y]) dis[Y]=dis[X]+z,q.push({Y,dis[Y]});
				}
			}
	//		cout<<dis[y]<<"\n";
			printf("%lld\n",dis[y]+w[x]+w[y]);
		}
	}
}
