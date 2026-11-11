#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[500005],kl[500005],l[500005],vis[500005],tk=0;long long dis[2005][2005],T;
struct st{
	int v,w;
};
vector<st> sz[500005];
inline int read(){
	int c;c=getchar();int ans=0;
	while(!isdigit(c)){
		c=getchar();
	}
	while(isdigit(c)){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
void disk(int ss){
	priority_queue<pair<long long,int> > q;
	for(int i=1;i<=m;i++){
		dis[ss][i]=1e18;vis[i]=0;
	}dis[ss][ss]=0;
	q.push({0,ss});
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=0;i<sz[x].size();i++){
			if(dis[ss][sz[x][i].v]>dis[ss][x]+sz[x][i].w){
				dis[ss][sz[x][i].v]=dis[ss][x]+sz[x][i].w;dis[sz[x][i].v][ss]=dis[ss][sz[x][i].v];
				if(!vis[sz[x][i].v]){
					q.push({-dis[ss][sz[x][i].v],sz[x][i].v});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		l[i]=read();tk+=l[i];
		for(int j=1;j<=l[i];j++){
			k[j]=read();kl[j]=read();
		}
		for(int j=1;j<=l[i];j++){
			for(int kk=j+1;kk<=l[i];kk++){
				sz[k[j]].push_back({k[kk],kl[j]+kl[kk]});
				sz[k[kk]].push_back({k[j],kl[j]+kl[kk]});
//				cout<<k[j]<<" "<<k[kk]<<" "<<kl[j]+kl[kk]<<endl;
			}
		}
	}T=kl[1];
	if(m<=2000)for(int i=1;i<=m;i++)disk(i);
	for(int i=1;i<=q;i++){
		int x,y;
		x=read();y=read();
		if(m<=2000)printf("%lld\n",dis[x][y]+w[x]+w[y]);
		else printf("%lld\n",T+T+w[x]+w[y]);
	}
}
