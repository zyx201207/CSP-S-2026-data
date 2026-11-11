#include<iostream>
using namespace std;
int n,m,dp[20005][20005];
int a[10005];
int sum;
int awy(int s,int x){
    int f=a[s];
    for(int i=s-1;i>=s-x+1;i--){
        f=f&a[i];
    }
    return f;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        sum=a[1];
        for(int i=2;i<=n;i++){
            sum=sum&a[i];
        }
        cout<<sum;
        return 0;
    }
    if(m==1){
        sum=a[1];
        for(int i=2;i<=n;i++){
            sum=max(sum,a[i]);
        }
        cout<<sum;
        return 0;
    }
    for(int i=m;i<=n;i++){
        for(int j=m;j<=n;j++){
            if(i==j) dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            else dp[i][j]=max(awy(j,m),max(dp[i-1][j],dp[i][j-1]));
        }
    }
    cout<<dp[n][n];
    return 0;
}
