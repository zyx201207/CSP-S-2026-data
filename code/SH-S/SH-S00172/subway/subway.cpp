#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,x,y;
int w[500005],k[505];
vector<int> a[505],t[505];
vector<int> A[500005],T[500005];
//站点i能直接前往的线路 
int dis[505][505];
//线路a到线路b的最小步行时间 
void ask(int x,int y){
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<A[x].size();i++){
		for(int j=0;j<A[y].size();j++){
			int u=A[x][i],v=A[y][j];
			ans=min(ans,w[x]+w[y]+dis[u][v]+T[x][i]+T[y][j]);
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			cin>>x;a[i].push_back(x);
			cin>>x;t[i].push_back(x);
			A[a[i][j]].push_back(i);
			T[a[i][j]].push_back(t[i][j]);
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		for(int j=0;j<A[i].size();j++){
			for(int k=j+1;k<A[i].size();k++){
				dis[A[i][j]][A[i][k]]=min(dis[A[i][j]][A[i][k]],T[i][j]+T[i][k]);
				dis[A[i][k]][A[i][j]]=min(dis[A[i][k]][A[i][j]],T[i][j]+T[i][k]);
				//cout<<T[i][j]+T[i][k]<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ask(x,y);
	}
}
