#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,d,t,c;
long long a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	    cin>>n>>d;
	    int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int dp[5005];
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<=j-1;k++){
					if(a[j]-a[k]<=d)dp[j]+=dp[k],dp[j]=max(dp[j],1);
				}if(dp[j]==2)ans++;
			}
		}	
		cout<<ans<<"\n";
	}
	return 0;
} 