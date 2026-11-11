#include<bits/stdc++.h>
using namespace std;
const int M=550,N=5e5+10;
long long Max=1e15;
int c,n,m,d,q;
long long W[N];
vector<int> e[N];
vector<long long> w[N];
long long f[M][M];
int k[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a;
	long long l;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%lld",&W[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%lld",&a,&l);
			e[a].push_back(i);
			w[a].push_back(l);
		}
	}
	/*for(int i=1;i<=m;i++){
		cout<<e[i].size()<<endl;
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			f[i][j]=Max;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			for(int z=0;z<e[i].size();z++){
				if(j==z) continue;
				f[e[i][j]][e[i][z]]=min(f[e[i][j]][e[i][z]],w[i][j]+w[i][z]);
				//cout<<i<<" "<<e[i][j]<<" "<<e[i][z]<<" "<<f[e[i][z]][e[i][j]]<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	int x,y;
	long long ans;
	while(q--)
	{
		scanf("%d%d",&x,&y);
		ans=Max;
		for(int i=0;i<e[x].size();i++){
			for(int j=0;j<e[y].size();j++){
				ans=min(ans,f[e[x][i]][e[y][j]]+w[x][i]+w[y][j]);
			}
		}
		cout<<ans+W[x]+W[y]<<endl;
	}
	return 0;
}


