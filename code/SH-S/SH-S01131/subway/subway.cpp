#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=50009;
int c,n,m,d,q,w[N],t[509][N],ans=0;
vector<int> z[N];
int f[509][509];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
			cin>>t[i][a];
			z[a].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<z[i].size();j++){
			for(int k=j+1;k<z[i].size();k++){
				f[z[i][j]][z[i][k]]=f[z[i][k]][z[i][j]]=t[z[i][j]][i]+t[z[i][k]][i];
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int k=1;k<=n;k++){
			for(int i=x;i<=k;i++){
				for(int j=k;j<=y;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		ans=f[x][y];
		cout<<ans<<" ";
		int cnt=1e9;
		for(int i=0;i<z[x].size();i++){
			cnt=min(ans,z[x][i]);
		}
		ans+=cnt;
		cnt=1e9;
		for(int i=0;i<z[y].size();i++){
			cnt=min(ans,z[y][i]);
		}
		ans+=cnt;
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
} 
