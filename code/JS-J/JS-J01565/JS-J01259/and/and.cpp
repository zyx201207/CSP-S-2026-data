#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N=2000+2 ;
ll n,m,a[N],dp[N][N] ;
bool flag=1 ;
int main(){
    freopen("and.in","r",stdin) ;
    freopen("and.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0);cout.tie(0);
    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        cin >> a[i] ;
        if(a[i]!=i-1) flag=0 ;
    }
    sort(a+1,a+n+1) ;
    if(n>2000){
        if(flag){// 10pts
            cout << a[n]-(1LL<<(m-1))+1 ;
            return 0 ;
        }
        int rem=a[n] ;
        for(int i=n-1;i>n-m;i--) rem&=a[i] ;
        cout << rem ;
        return 0 ;
    }
    for(int i=1;i<=n;i++) dp[i][1]=max(dp[i-1][1],a[i]) ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max((dp[i-1][j-1]&a[i]),max(dp[i][j],dp[i-1][j])) ;
        }
    }
    cout << dp[n][m] ;
    return 0 ;
}
