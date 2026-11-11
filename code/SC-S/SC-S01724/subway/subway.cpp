#include<bits/stdc++.h>
using namespace std;
const int N=5e5+91;
int c,n,m,d,q/*,t[N][505]*/,k[N];
vector<int> stn[N];
map< pair<int,int> ,long long >t;
long long dis[505][505],w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int x,y;
			scanf("%d%d",&x,&y);
			t[{x,i}]=y;
			stn[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<stn[i].size();j++){
			for(int l=j+1;l<stn[i].size();l++){
				int x=stn[i][j],y=stn[i][l];
				dis[x][y]=min({dis[x][y],dis[y][x],t[{i,x}]+t[{i,y}]});
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		long long  ans=w[x]+w[y];
		long long rest=2e18;
		for(int j=0;j<stn[x].size();j++)
			for(int l=0;l<stn[y].size();l++){
				int l1=stn[x][j],l2=stn[y][l]; 
				rest=min({rest,dis[l1][l2]+t[{x,l1}]+t[{y,l2}],dis[l2][l1]+t[{x,l1}]+t[{y,l2}]});
	
			}
		ans+=rest;
		printf("%lld\n",ans);	
	}
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/