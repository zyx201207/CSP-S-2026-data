#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;

int c,t,n,d,x[N],dp[N],s[N];

void work(){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			dp[j]=n+1;
			s[j]=0;
		}
		dp[i]=0;
		s[i]=1;
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(x[k]-x[j]>d) break;
				if(dp[j]+1<dp[k]) dp[k]=dp[j]+1,s[k]=s[j];
				else if(dp[j]+1==dp[k]) s[k]+=s[j];
			}
			if(s[j]==2 && i!=j) ans++;
		}
	}
	cout<<ans<<"\n";
	return ;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		work();
	}

	return 0;
}

