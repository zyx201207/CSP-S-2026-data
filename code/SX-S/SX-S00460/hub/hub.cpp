#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
const int N=305;
int fw,t;
int n,m,f[N][N][N];
vector<int> v[N];
void dfs(int x,int fa){
//	cout<<x<<'\n';
	bool bl=1;
	for (auto i:v[x]){
		if (i==fa)continue;
		bl=0;
		dfs(i,x);
		f[x][0][0]=0;
		int mx=0;
		for (int j=1;j<=n;j++){
			f[x][0][j]=f[i][0][j-1]+1;
		for (int j=1;j<=m;j++){
			for (int k=1;k<=j;k++){
				for (int g=0;g<=n;g++){
					if (k==0)tmp=g;
					if (j!=k)f[x][j][0]=min(f[x][j][0],max({f[x][j-k-1][0],f[i][k][g],tmp}));
					for (int o=0;o<=mx;o++)f[x][j][g+1]=min(f[x][j][g+1],max(f[x][j-k][o+1],f[i][k][g]));
					if (x==3&&j==1&&g==0&&f[x][j][g+1]==1){
//						cout<<f[x][j-k][g+1]<<' '<<f[i][k][g]<<' '<<k<<' '<<i<<'\n';
					}
				}                                                  
			}                                      
		}                                
	}
	for (int j=0;j<=m;j++){
		for (int k=0;k<=n;k++){
//			if (f[x][j][k]<1e15)cout<<x<<' '<<j<<' '<<k<<' '<<f[x][j][k]<<'\n';	
		}
	}
	if (bl){
		f[x][1][0]=0;
		f[x][0][1]=0;
		f[x][0][0]=0;
		return;
	}
}
void act(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)v[i].clear();
	for (int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(f,0x3f,sizeof(f));
	dfs(1,-1);
//	cout<<f[3][0][1]<<'\n';
	int ans=f[1][m][0];
	for (int i=1;i<=n;i++){
		ans=min(ans,max(f[1][m][i],i));
	}       
	cout<<ans<<'\n';
//	exit(0);
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>fw>>t;
	while (t--){
		act();
	}
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
