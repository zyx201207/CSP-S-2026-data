#include<bits/stdc++.h>
using namespace std;
int dp[2001][2001];
char a[1000001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    int n;
    cin>>n;
    int len=0;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        for(int j=1;j<=x;j++) a[++len]=y;
    }
    for(int i=1;i<len;i++){
        if(a[i]==a[i+1]) dp[i][i+1]=0;
        else dp[i][i+1]=1;
    }
    for(int k=2;k<=len;k++){
        for(int r=1;r+k-1<=len;r++){
            int l=r+k-1;
            if(a[r]==a[l])dp[r][l]=dp[r+1][l-1];
            else dp[r][l]=dp[r+1][l-1]+1;
        }
    }
    cout<<dp[1][len];
    return 0;
}
