#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int a=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+(c^48);
		c=getchar();
	}
	return a*f;
} 
const int M=5e5+5,N=505;
int c,n,m,d,q;
ll ans,cost[N][N],w[M];
vector<pair<int,int>>g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=1ll*read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			g[a].emplace_back(make_pair(i,t));
		}
	}
	memset(cost,0x3f3f3f3f,sizeof cost);
	for(int i=1;i<=n;i++)cost[i][i]=0;
	for(int i=1;i<=m;i++){
		for(const pair<int,int>&u:g[i]){
			for(const pair<int,int>&v:g[i]){
				if(u==v)continue;
				cost[u.first][v.first]=min(cost[u.first][v.first],1ll*u.second+1ll*v.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		ans=LLONG_MAX;
		for(const pair<int,int>&u:g[x]){
			for(const pair<int,int>&v:g[y]){
				ans=min(ans,1ll*u.second+1ll*v.second+cost[u.first][v.first]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
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
