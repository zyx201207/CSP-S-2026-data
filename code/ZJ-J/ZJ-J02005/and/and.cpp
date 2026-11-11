#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
int dp[N];
int a[N];
int n,m;
//wdf这我凭啥样例3、5过不了啊
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=(1<<30)-1;
    for(int i=1;i<=n;i++){
        for(int j=min(m,n);j>=1;j--){
            dp[j]=max(dp[j],(dp[j-1] & a[i]));
        }
        // dp[1] = max(a[i],dp[1]);
        // ans = max(ans, dp[m]);
    }
    cout<<dp[m]<<endl;
	return 0;
}//rp++!