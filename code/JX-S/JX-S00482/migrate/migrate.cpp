#include<bits/stdc++.h>
using namespace std;
long long n,t,k,a[200005],g[1001][1001],bj[1001][1001],temp[1001][1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c>>t;
	for(int ww=1;ww<=t;ww++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		memset(g,0x3f,sizeof(g));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=k && i!=j)
				{
					bj[i][j]=1;
					g[i][j]=min(g[i][j],abs(a[i]-a[j]));
				}
			}
		}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int u=i+1;u<j;u++){
					if(bj[i][u]!=0 && bj[u][j]!=0){
						if(g[i][u]+g[u][j]<g[i][j]){
							g[i][j]=g[i][u]+g[u][j];
							bj[i][j]=1;
						}
						else if((g[i][u]+g[u][j])==g[i][j]){
							bj[i][j]=bj[i][j]+1;
						}
					}
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(bj[i][j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
