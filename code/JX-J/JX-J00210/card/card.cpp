#include<bits/stdc++.h>
using namespace std;
int n,m,x[200005],dp[6015][5005],ma[100005],r[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=n;i>=1;i--){
        if(r[x[i]]==0){
            int cnt=dp[i+1][0],j=0;
            while(cnt!=0){
                cnt--;
                j++;
                dp[i][j]=dp[i+1][j];
                ma[dp[i][j]]++;
            }
            dp[i][0]=dp[i+1][0]+1;
            dp[i][dp[i][0]]=x[i];
            ma[x[i]]++;
        }
        else{
            int l=r[x[i]];
            int cnt=dp[l][0],j=0;
            while(cnt!=0){
                cnt--;
                j++;
                dp[i][j]=dp[l][j];
                ma[dp[i][j]]++;
            }
            dp[i][0]=dp[l][0];
        }
        if(r[x[i]]==0)r[x[i]]=i;
    }
    for(int i=1;i<=m;i++)cout<<ma[i]<<" ";
    return 0;
}
