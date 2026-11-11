#include<bits/stdc++.h>
using namespace std;
int n,f[2000001],ans,c,t,g[2000001];
long long x[2000001],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<n-1;i++){
			f[i]=0;
			g[i]=1;
			for(int j=i+1;j<=n;j++){
				f[j]=1e9;
				for(int k=j-1;x[k]+d>=x[j]&&k>=i;k--){
					if(f[j]>f[k]+1){
						f[j]=f[k]+1;
						g[j]=g[k];
					}else if(f[j]==f[k]+1)g[j]+=g[k];
				}
			}for(int j=1;j<=n;j++)ans+=(g[j]==2);
		}cout<<ans<<endl;
	}return 0;
}
