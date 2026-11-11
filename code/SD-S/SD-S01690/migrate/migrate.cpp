#include<bits/stdc++.h>
using namespace std;
long long f[100010],g[100010],a[100010];
int main(){
	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	long long c,t,n,d;
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++)	f[j]=1e18,g[j]=0;
			f[i]=0,g[i]=1;
			for(int j=i;j<=n;j++){
				for(int k=j+1;a[k]-a[j]<=d&&k<=n;k++){
					if(f[k]>f[j]+1)	f[k]=f[j]+1,g[k]=g[j];
					else if(f[k]==f[j]+1)	g[k]+=g[j];
				}
				if(g[j]==2)	ans++;
//				cout<<g[j]<<' ';
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}

