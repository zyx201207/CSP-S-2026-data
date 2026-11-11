# include<bits/stdc++.h>
using namespace std ;

long long n,a[200005],ans ;
char c[200005] ;

int main()
{
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
    cin >> n ;
    for (int i=1 ; i<=n ; i++) cin >> a[i] >> c[i] ;
    int i=1,j=n ;
    while (i<j){
        long long m=min(a[i],a[j]) ;
        if (c[i]==c[j]){
            a[i]-=m,a[j]-=m ;
        }
        else{
            ans+=m ;
            a[i]-=m,a[j]-=m ;
        }
        if (a[i]==0) i++ ;
        if (a[j]==0) j-- ;
    }
    cout << ans ;
    return 0 ;
}
