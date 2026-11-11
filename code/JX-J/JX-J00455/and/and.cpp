#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int n,m,a[N],dp[N][N];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dp[i][m]=a[i];
    for(int i=1;i<=n;i++){
        for(int j=m-1;j>=0;j--){
            dp[i][j]=max(dp[i][j],dp[i][j+1]&a[i]);
        }
    }
    int maxn=INT_MIN;
    for(int i=0;i<m;i++) maxn=max(maxn,dp[n][i]);
    cout<<maxn;
    return 0;
}
