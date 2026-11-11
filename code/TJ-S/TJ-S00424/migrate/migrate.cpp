#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,f[5005][5005],x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(f,0,sizeof(f));
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<n-1;i++){
			f[i][i]=1;
			f[i][i+1]+=(x[i+1]-x[i]>d);
		}
		f[n-1][n-1]=1;
		for(int l=3;l<=n;l++){
			for(int i=0;i<n;i++){
				int j=i+l-1;
				for(int k=i;k<j;k++){
					if(x[k+1]-x[k]>d){
						f[i][j]+=f[i][k]*f[k+1][j];
					}
				}
			}
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(f[i][j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
