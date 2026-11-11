#include<bits/stdc++.h>
using namespace std;
int n,d;
int x[310];
int f[310][310][310];
void sol(){
	memset(f,0,sizeof(f));
	cin >>n>>d;
	for(int i=1;i<=n;i++)cin >>x[i];
	for(int u=1;u<=n;u++)
		for(int v=u+1;v<=n;v++)
			for(int j=u;j<v;j++)
				if(x[v]-x[j]<=d){
					if(u==j)f[u][v][1]=1;
					else 
					for(int m=2;m<n;m++)
						f[u][v][m]+=f[u][j][m-1];
				}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			for(int m=1;m<n;m++){
			if(f[i][j][m]==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t=1,c;
	cin >>c>>t;
	while(t--)
		sol();
}
