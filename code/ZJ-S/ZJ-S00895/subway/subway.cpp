#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500001];
int s[500001];
int c,n,m,d,q,cnt;
int f[1001][1001];
int p[100001];
int k[100001];
int x,y,z;
vector<pair<int,int>>t[100001];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,kkk;
			cin>>x>>kkk;
			t[x].push_back({i,kkk});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		int len=t[i].size();
		for(int j=0;j<len;j++){
			for(int k=0;k<len;k++){
				int u=t[i][j].first,y=t[i][j].second;
				int v=t[i][k].first,z=t[i][k].second;
				f[u][v]=f[v][u]=min(f[u][v],y+z);
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k){
				continue;
			}
			for(int j=1;j<=n;j++){
				if(f[i][j]>f[i][k]+f[k][j]) f[i][j]=f[i][k]+f[k][j];
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int lxm=p[x]+p[y];
		int ans=1e18;
		for(int j=0;j<t[x].size();j++){
			for(int k=0;k<t[y].size();k++){
				int u=t[x][j].first,w=t[x][j].second;
				int v=t[y][k].first,z=t[y][k].second;
				ans=min(ans,w+z+f[u][v]);	
			}
		}
		cout<<lxm+ans<<endl;
	}
	return 0;
}