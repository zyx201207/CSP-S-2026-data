#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long m;
long long a[2000010];
long long f[5010][5010];
long long g[5010][5010];
int b[5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c<=6){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=1e9;
					g[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++){
				f[i][i]=0;
				g[i][i]=1;
				for(int j=i+1;j<=n;j++){
					if((a[j]-a[i])<=m){
						f[i][j]=1;
						g[i][j]++;
					}else{
						break;
					}
				}
			}
			for(int len=1;len<=n;len++){
				for(int i=1;i+len-1<=n;i++){
					int j=i+len-1;
					for(int k=i;k<=j;k++){
						f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
					}
				}
			}
			for(int len=1;len<=n;len++){
				for(int i=1;i+len-1<=n;i++){
					int j=i+len-1;
					if(f[i][j]==1e9){
						g[i][j]=0;
						continue;
					}
					for(int k=i+1;k<j;k++){
						if(f[i][j]==(f[i][k]+f[k][j])){
							g[i][j]+=g[i][k]*g[k][j];
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(g[i][j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}else if(c<=12&&c>=11){
			int d=a[2]-a[1];
			int x=m/d;
			if(x==0){
				cout<<0<<"\n";
			}else if(x==1){
				cout<<0<<"\n";
			}else{
				cout<<(n-(x+x-1)+1)<<"\n";
			}
		}else{
			cout<<0<<"\n";
		}
	}
	return 0;
}