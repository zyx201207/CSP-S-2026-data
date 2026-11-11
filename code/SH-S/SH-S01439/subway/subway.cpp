#include<bits/stdc++.h>
using namespace std;
long long c,m,n,d,q,w[500010],g[510][510];
map<long long,long long>a[500010];
vector<long long>b[510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		long long k,c[500010];
		cin>>k;
		for(int j=1;j<=k;j++){
			long long ne,t;
			cin>>ne>>t;
			a[ne][i]=t;
			c[j]=ne;
		}
		sort(c+1,c+k+1);
		for(int j=1;j<=k;j++){
			b[i].push_back(c[j]);
		}
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			g[i][j]=g[j][i]=1000000000000;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
			for(int l=0,r=0;l<b[i].size()&&r<b[j].size();l++){
				while(b[i][l]>b[j][r]&&r<b[j].size()){
					r++;
				}
				if(b[i][l]==b[j][r])g[i][j]=g[j][i]=min(g[i][j],a[b[i][l]][i]+a[b[i][l]][j]);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if(k==i||k==j)continue;
				g[i][j]=g[j][i]=min(g[i][j],g[i][k]+g[j][k]);
			}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=1000000000000;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[x][i]>0&&a[y][j]>0)ans=min(ans,a[x][i]+a[y][j]+g[i][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
