#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,s,q;
int w[N],k[M],d[M][M];
vector<int> e[N],t[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>s>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			d[i][j]=2e18;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,a,b;j<=k[i];j++){
			cin>>a>>b;
			e[a].push_back(i);
			t[a].push_back(b);
		} 
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			for(int r=j;r<e[i].size();r++){
				if(r==j){
					d[e[i][j]][e[i][j]]=0;
				}
				d[e[i][j]][e[i][r]]=min(d[e[i][j]][e[i][r]],t[i][r]+t[i][j]);
				d[e[i][r]][e[i][j]]=d[e[i][j]][e[i][r]];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		int ans=2e18;
		cin>>x>>y;
		for(int j=0;j<e[x].size();j++){
			for(int r=0;r<e[y].size();r++){
				ans=min(ans,t[x][j]+t[y][r]+d[e[x][j]][e[y][r]]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
//看到n<=500，就想到了floyd,不知道打的对不对，求过！！ 
