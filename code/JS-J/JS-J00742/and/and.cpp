#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[200005];

	cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;

    for(int i=1;i<=n;i++)
        dp[i][1]=max(dp[n-1][1],a[i]);
    if(m==1){
        cout<<dp[n][1]<<endl;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j)
                    ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(i>j)
                dp[i][j]=max({dp[i-1][j],dp[i-1][j-1]&a[i],dp[i][j]});
            ans=max(ans,dp[i][j]);
        }

    }


    for(int i=m;i<=n;i++)
        ans=max(ans,dp[i][m]);
    cout<<ans<<endl;
    return 0;
}
