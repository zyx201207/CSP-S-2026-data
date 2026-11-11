#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,m,i,j,k,l,s,f[5005][5005],g[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		vector<ll>a(n);s=0;
		for(ll&u:a)cin>>u;
		for(i=0;i<=n;i++)for(j=0;j<=n;j++)f[i][j]=3e18,g[i][j]=0;
		for(l=1;l<=n;l++){
			for(i=0;i+l-1<n;i++){
				j=i+l-1;
				if(l==1)f[i][i]=0,g[i][j]=1;
				else if(l>1){
					if(a[i]+m>=a[j])f[i][j]=1,g[i][j]++;
					for(k=i+1;k<j;k++){
						if(f[i][k]>=2e18||f[k][j]>=2e18)continue;
						if(a[k]+m>=a[j]){
							if(f[i][k]+f[k][j]<f[i][j])g[i][j]=g[i][k]*g[k][j],f[i][j]=f[i][k]+f[k][j];
							else if(f[i][k]+f[k][j]==f[i][j])g[i][j]+=g[i][k]*g[k][j];
						}
					}
				}
				if(g[i][j]==2)s++;
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}
