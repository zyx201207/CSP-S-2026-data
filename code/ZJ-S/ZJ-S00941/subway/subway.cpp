//15:04 T2 done  test7 0.98s
//15:26 unO2 0.96s  O2 0.36s   
#include<bits/stdc++.h>
using namespace std;
long long cccc,n,m,d,q,w[500010],f[510][510];
vector<long long>e1[500010],e2[500010];
long long el[500010];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cccc>>n>>m>>d>>q;
	memset(f,0x3f,sizeof f);
	for(long long i=1;i<=n;i++)f[i][i]=0; 
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long xxx;
		cin>>xxx;
		for(long long j=1;j<=xxx;j++){
			long long x,y;
			cin>>x>>y;
			e1[x].push_back(i);
			e2[x].push_back(y);
			el[x]++;
		}
	}
	for(long long i=1;i<=m;i++){
		//cout<<i<<":";
		for(long long j=0;j<el[i];j++){
			for(long long k=j+1;k<el[i];k++){
		//		cout<<e1[i][j]<<' '<<e1[i][k]<<'\n';
				f[e1[i][j]][e1[i][k]]=f[e1[i][k]][e1[i][j]]=min(f[e1[i][j]][e1[i][k]],e2[i][k]+e2[i][j]);
			}
		}
//		cout<<"\n";
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	//if(f[i][k]<1e18)
	for(int j=1;j<=n;j++)
	f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	/*
	for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++)cout<<f[i][j]<<' ';cout<<'\n';}*/
	while(q--){
		long long x,y,ans=1e18;
		cin>>x>>y;
		for(long long i=0;i<el[x];i++){
			for(long long j=0;j<el[y];j++){
				ans=min(ans,e2[x][i]+e2[y][j]+f[e1[x][i]][e1[y][j]]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
/*
O(n^3+md^2+qd^2) 
*/ 
