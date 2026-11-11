#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[2000005],dp[5005][5005],ans=-1e9;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        dp[1][i]=a[i];
    }
    for(int i=2;i<=m;i++){
        for(int j=i;j<=n;j++){
            for(int k=i-1;k<=j-1;k++){
                dp[i][j]=max(dp[i][j],dp[i-1][k]&a[j]);
            }
        }
    }
    for(int i=m;i<=n;i++){
        ans=max(ans,dp[m][i]);
    }
    cout << ans;
}