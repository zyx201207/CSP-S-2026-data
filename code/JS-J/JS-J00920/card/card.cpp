# include <bits/stdc++.h>
using namespace std ;

int n,m,a[200005],idx,ans[300005] ;
queue<int> q ;

int main()
{
    freopen("card.in","r",stdin) ;
    freopen("card.out","w",stdout) ;
    cin >> n >> m ;
    for (int i=1 ; i<=n ; i++) cin >> a[i],q.push(a[i]) ;
    for (int o=1 ; o<=n ; o++){
        for (int k=1 ; k<=n-o+1 ; k++){
            for (int i=k ; i<=n ; i++)
                if (a[i]==q.front()) idx=i ;
            for (int i=idx ; i<=n ; i++) q.pop() ;
            q.push(a[k]) ;
        }
        for (int j=1 ; j<=q.size() ; j++){
            ans[q.front()]++ ;
            q.push(q.front()) ;
            q.pop() ;
        }
        a[o]=0 ;
    }
    for (int i=1 ; i<=m ; i++)
        cout << ans[m] << ' ' ;
    return 0 ;
}
