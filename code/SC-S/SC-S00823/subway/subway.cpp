#include<bits/stdc++.h>
using namespace std;
int read(){
	int _1=0;char _3=getchar();
	while(_3<'0'||_3>'9') _3=getchar();
	while(_3>='0'&&_3<='9')
		_1=(_1<<3)+(_1<<1)+(_3-48),_3=getchar();
	return _1;
}
const int N=5e5+505;
int val[N];long long inf=1e18,dis[505][505];
vector<pair<int,int>>e[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) cin>>val[i];
	for(int i=1,k;i<=n;i++){
		k=read();
		for(int j=1,v,w;j<=k;j++){
			v=read(),w=read();
			e[v].push_back(make_pair(i,w));
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dis[i][j]=inf;
	for(int i=1;i<=m;i++)
		for(int j=0;j<e[i].size()-1;j++){
			int u=e[i][j].first,w1=e[i][j].second;
			for(int k=j+1;k<e[i].size();k++){
				int v=e[i][k].first,w2=e[i][k].second;
				dis[u][v]=min(dis[u][v],(long long)w1+w2);
			}
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[k][i]+dis[k][j]);
	for(int T=1,x,y;T<=q;T++){
		x=read(),y=read();long long ans=inf;
		for(auto ex:e[x]) for(auto ey:e[y])
			ans=min(ans,dis[ex.first][ey.first]+ex.second+ey.second+val[x]+val[y]);
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}