#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,sum;
int a[500005],c[500005];
int dp[5005][5005];
bool check(){
    for(int i=2;i<n;i++){
        if(c[i]!=c[i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=a[i]-a[i-1];
    }
    if(check()){
        if(c[2]!=0){
            int i=1;
            while(sum<=m){
                sum+=i*c[2];
                i++;
                if(sum>m) i--;
            }
            if(i<=n) cout<<i<<endl;
            else cout<<n<<endl;
        }
        else cout<<n<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
        dp[i][i+1]=a[i+1]-a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j+i<=n;j++){
            dp[j][j+i]=dp[j][j+i-1]+dp[j+i-1][j+i]*j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(dp[i][j]<=m){
                maxn=max(maxn,j-i+1);
            }
        }
    }
    cout<<maxn<<endl;
    return 0;
}
