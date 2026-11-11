//O(nm),for1~19n<=2e5,m<=3e3,O<=6e8
#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=3005;
int a[N],l[M];bool dp[N][M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m>100001){
        for(int i=1;i<=n;i++)if(a[i]!=a[i+1])cout<<i<<' ';
        return 0;
    }
    for(int i=n;i>=1;i--){
        if(l[a[i]])for(int j=1;j<=m;j++)dp[i][j]=dp[l[a[i]]][j];
        else{
            l[a[i]]=i;
            for(int j=1;j<=m;j++)dp[i][j]=dp[i+1][j];
            dp[i][a[i]]=1;
        }
    }
    for(int j=1;j<=m;j++){
        int cnt=0;
        for(int i=1;i<=n;i++)cnt+=dp[i][j];
        cout<<cnt<<' ';
    }
    return 0;
}
