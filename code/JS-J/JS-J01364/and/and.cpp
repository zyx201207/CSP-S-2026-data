#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 10 ;
int n,m ;
int a[N] ;
int ans = -1  ;
inline void dfs(int x,int cnt , int sum){
    if(cnt == m||x == n + 1){
            if(cnt == m ){
                 ans = max(ans,sum) ;
            }

        return ;
    }
    if(cnt == 0){
        sum = a[x] ;
    }
    dfs(x+1,cnt+1,sum & a[x]) ;
    dfs(x+1,cnt,sum) ;
}
int main(){
    freopen("and.in","r",stdin) ;
    freopen("and.out","w",stdout) ;
    scanf("%d %d",&n,&m) ;
    long long sum = 0 ;
    for(int i  = 1 ; i <= n ; i++){
        scanf("%d",&a[i] ) ;
    }
    sort(a+1,a+n+1) ;
    int mx = a[1] ;
    sum = a[1] ;
    for(int i = 2 ; i <= n ;  i++){
        sum = sum & a[i] ;
        mx = max(mx,a[i]) ;
    }

    if(n == m){
        ans = sum ;
    }else if(m == 1){
        ans = mx ;
    }else if(m == 2){

        for(int i = n ; i >= 2 ; i--){
                int x = a[i] & a[i-1];
            for(int j = i-1 ; i >= 1 ; i--){
                x = max(a[i] & a[j] , x) ;
            }
            ans = max(x,ans) ;
        }
    }else{
        dfs(1,0,0) ;
    }

    printf("%d",ans) ;
    return 0 ;
}
