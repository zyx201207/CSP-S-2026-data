#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PID "and"
#define FIN freopen(PID".in","r",stdin)
#define FOU freopen(PID".out","w",stdout)
const int N=2e5+5;
int n,m,a[N],dp[N];

int main(){
	FIN;
	FOU;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++){
		for(int j=m;j>0;j--){
			if(dp[j-1]==-1) dp[j]=max(dp[j],a[i]);
			else dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}

