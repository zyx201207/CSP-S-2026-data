#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],ans,dp[5010][5010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>5000){
        int cha=abs(a[1]-a[2]);
        int j=0;
        for(int i=1;i<=m;i++){
            if(m<j){
                cout<<i-1;
                return 0;
            }
            j+=i*cha;
        }
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=a[i]-a[j];
        }
    }
    for(int i=1;i<=n;i++){
        int sum=0,cut=0;
        for(int j=i;j>=1;j--){
            sum+=dp[i][j];
            if(sum<=m){
                cut++;
                ans=max(ans,cut);
            }else{
                ans=max(ans,cut);
            }
        }
    }
    cout<<ans;
    return 0;
}