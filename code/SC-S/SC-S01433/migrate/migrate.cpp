#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[2000005],f[5005][5005],sum,s[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>m;
		bool l=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=a[2]-a[1])l=1;
		}
		if(l==0){
			if(n-2*m+1>0)cout<<n-2*m+1<<endl;
			else cout<<0<<endl;
		}else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=m)f[i][j]=1;
					else f[i][j]=1e9;
					s[i][j]=0;
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(a[j]-a[k]<=m&&a[i]-a[k]<=m&&f[i][j]>f[i][m]+f[m][j]&&j!=k&&j!=i&&k!=i)f[i][j]=f[i][m]+f[m][j];
					}
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(a[j]-a[k]<=m&&a[i]-a[k]<=m&&f[i][j]>=f[i][m]+f[m][j]&&j!=k&&j!=i&&k!=i&&i<k&&k<j){
							if(f[i][j]==f[i][m]+f[m][j]){
								s[i][j]++;
							}
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(s[i][j]==2)sum++;
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}