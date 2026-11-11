#include<bits/stdc++.h>
#define int long long
using namespace std;
int cc,n,m,d,q;
int w[500009],len[509],dis[509][509];
vector<pair<int,int> > v[500009];
int x,y;
int rd(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cc=rd();n=rd();m=rd();d=rd();q=rd();
	for(int i=1;i<=m;i++) w[i]=rd();
	for(int i=1;i<=n;i++){
		len[i]=rd();
		for(int j=1;j<=len[i];j++){
			x=rd();y=rd();
			v[x].push_back(make_pair(y,i));
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if (i!=j)
				dis[i][j]=2e18;
	for(int i=1;i<=m;i++){
		int aaa=v[i].size();
		for(int j=0;j<aaa;j++)
			for(int k=0;k<aaa;k++)
				dis[v[i][j].second][v[i][k].second]=min(dis[v[i][j].second][v[i][k].second],v[i][j].first+v[i][k].first);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//	for(int i=1;i<=n;i++,cout<<endl)
//		for(int j=1;j<=n;j++)
//			cout<<dis[i][j]<<' ';
	while(q--){
		x=rd();y=rd();
		int ans=2e18;
		for(int i=0;i<v[x].size();i++)
			for(int j=0;j<v[y].size();j++)
				ans=min(ans,dis[v[x][i].second][v[y][j].second]+v[x][i].first+v[y][j].first);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
