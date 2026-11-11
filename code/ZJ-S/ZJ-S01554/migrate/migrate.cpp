#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],dp[2000005],dpp[2000005];
void dfs(int k,int st){
	//cout<<k<<" "<<st<<"\n";
	if(st==dp[k]){
		dpp[k]++;
	}
	for(int i=k+1;i<=n;i++){
		if(x[i]-x[k]>d)break;
		//cout<<"ghdfhsg";
		dfs(i,st+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0,anss=0,Ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int l=1;l<=n;l++){
			for(int i=1;i<=n;i++){
				dp[i]=INT_MAX;
				dpp[i]=0;
			}
			dp[l]=0;
			for(int i=l;i<=n;i++){
				for(int j=i-1;j>=l;j--){
					if(x[i]-x[j]>d)break;
					dp[i]=min(dp[j]+1,dp[i]);
				}
			}
			dfs(l,0);
			for(int i=l;i<=n;i++){
				if(dpp[i]==2)ans++;
				//cout<<dpp[i]<<" ";
			}//cout<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
