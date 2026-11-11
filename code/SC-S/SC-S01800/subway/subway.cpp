#include<bits/stdc++.h>
using namespace std;
long long dis[502][502];
int w[500002],n,m,q;
vector<pair<int,int> > v[500002];
int read(){
	char c=getchar();
	int k=0;
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long k,c,d,a,t,x,y,lx,ly,ans;
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i) w[i]=read();
	for(int i=1;i<=n;++i){
		k=read();
		for(int j=1;j<=k;++j){
			a=read(),t=read();
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<v[i].size();++j){
			for(k=0;k<v[i].size();++k){
				if(k==j) continue;
				x=v[i][j].first,y=v[i][k].first;
				lx=v[i][j].second,ly=v[i][k].second;
				dis[x][y]=min(lx+ly,dis[x][y]);
				dis[y][x]=min(lx+ly,dis[y][x]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				dis[j][i]=min(dis[j][i],dis[j][k]+dis[k][i]);
			}
		}
	}
	while(q--){
		ans=1e18;
		cin>>x>>y;
		for(int i=0;i<v[x].size();++i){
			for(int j=0;j<v[y].size();++j){
				ans=min(ans,v[x][i].second+v[y][j].second+dis[v[x][i].first][v[y][j].first]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}