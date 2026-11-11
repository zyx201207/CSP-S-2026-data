#include<bits/stdc++.h>
using namespace std;

int const N=1e5+10;
int const INF=1e9+10;
int c,n,m,d,q;
int w[N],k[505];
int t[505][N];
int a[505][N];
int ans=INF;
bool v[505];
bool A=1,B=1;
void dfs(int x,int y,int z){
	if(x==y&&ans>z){
		ans=t;
		return;
	}
	if(v[a[x][y+1]]!&&y+1<=N){
		dfs(x,y+1,z+t[x][y+1]);
	}
	if(v[v[x][y-1]]!&&y-1>0){
		dfs(x,y-1,z+t[x][y-1]);
	}
	for(int k=1;k+x<=n||x-k>1;k++){
		if(v[x+k][y]]!&&v[x+k][y+1]]!&&y+1<=N&&a[x][y]==a[x+k][y]&&k+x<=n){
			dfs(x+k,y+1,z+t[x+k][y]+t[x+k][y+1]);
		}
		if(v[x-k][y]]!&&v[x-k][y-1]]!&&y-1>0&&a[x][y]==a[x+k][y]&&x-k>1){
			dfs(x-k,y+1,z+t[x-k][y]+t[x-k][y-1]);
		}
		if(v[x+k][y]]!&&v[x+k][y-1]]!&&y-1>0&&a[x][y]==a[x+k][y]&&k+x<=n){
			dfs(x+k,y+1,z+t[x+k][y]+t[x+k][y-1]);
		}
		if(v[x-k][y]]!&&v[x-k][y+1]]!&&y+1<=n&&a[x][y]==a[x+k][y]&&x-k>1){
			dfs(x-k,y+1,z+t[x-k][y]+t[x-k][y+1]);
		}
	}
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2)A=0;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	for(int r=1;r<=q;r++){
		int x,y;
		cin>>x>>y;

		dfs(x,y,0);
		cout<<ans+w[x]+w[y]<<endl;
		ans=INF;
	}
	
	return 0;
} 
