#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5,inf=0x3f3f3f3f3f3f3f3f;
long long C,T,n,m,a[N],v[N],dp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		long long ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			memset(dp,0,sizeof dp);
			memset(v,inf,sizeof v);
			int t=0;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[j-1]>m) break;
				long long k=j-1,s=j-1; t=v[k]+1;
				while(a[k+1]-a[s]<=m&&k<=n){
					k++;
					if(t==v[k]) dp[k]++;
					if(t<v[k]){v[k]=t; dp[k]=1;}
				}
				if(dp[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 