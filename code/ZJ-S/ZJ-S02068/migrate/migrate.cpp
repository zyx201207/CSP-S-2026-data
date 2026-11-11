#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
int n,d;
int x[N];
struct node{
	int di,u,st;
	bool operator <(const node w)const{
		return di>w.di;
	}
};
vector<pair<int,int>>g[N];
priority_queue<node>q;
int dis[N][N],num[N][N];
void floyd(){
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j){
			for(int k=i+1;k<j;++k){
				if(dis[i][j]==dis[i][k]+dis[k][j]){
					num[i][j]++;
				}
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					num[i][j]=num[i][k]*num[k][j];
				}
			}
		}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		for(int i=1;i<=n;++i)g[i].clear();
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;++i){
			dis[i][i]=0;
			for(int j=i+1;j<=n;++j)dis[i][j]=1e9,num[i][j]=0;
		}
		for(int i=1;i<=n;++i)cin>>x[i];
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(x[j]-x[i]<=d){
					dis[i][j]=1;
					num[i][j]=1;
				}
		floyd();
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(num[i][j]==2)ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
