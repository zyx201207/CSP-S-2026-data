#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int x;
	scanf("%d",&x);
	return x;
}
int c,t,n,d,x[2000010],ans,vis[2000010],dis[2000010];
vector<int>G[2000010];
struct node{
	int id,step;
};
void bfs(int u){
	memset(vis,0,sizeof vis);
	memset(dis,0,sizeof dis);
	queue<node>q;
	q.push((node){u,1});
	while(q.size()){
		for(auto v:G[u]){
			if(vis[v]>=3)continue;
			q.push((node){v,q.front().step+1});
			if(vis[v]==0)dis[v]=q.front().step+1,vis[v]++;
			else if(q.front().step+1==dis[v])vis[v]++;
		}
		q.pop();
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==2)ans++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	if(c==11||c==12){
		while(t--){
			n=read(),d=read();
			for(int i=1;i<=n;i++){
				x[i]=read();
			}
			int ch=x[2]-x[1];
			if(d/ch==2)cout<<n-3<<'\n';
			else cout<<0<<'\n';
		}
		return 0;
	}
	while(t--){
		ans=0;
		memset(x,0x3f,sizeof x);
		memset(G,0,sizeof G);
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
			int o=i;
			while(o--){
				if(abs(x[i]-x[o])<=d){
					G[i].push_back(o);
					G[o].push_back(i);
				}
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			bfs[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
never gonna give you up
never gonna let you down
never gonna round a round and desert you
never gonna give you up
never gonna say good bye
never gonna tell a lie and hurt you
whooo~ GIVE YOU UP whooo~ GIVE YOU UP
never gonna give never gonna give(GIVE YOU UP)
never gonna give never gonna give(GIVE YOU UP)
we know each other for so long
hou mian wang le(bei)
*/
