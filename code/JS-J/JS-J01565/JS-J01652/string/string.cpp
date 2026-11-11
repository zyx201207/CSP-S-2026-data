//funk
#include <bits/stdc++.h>
#define ll long long
#define isok cout << "ok" << endl
#define DB(s,a) cout << s << ":" << a << endl
using namespace std ;
const ll MAXN = 200005 ;
ll n , i , cnt , ans , i1 = 1 , i2 = 1 , L , a[MAXN] , aa[MAXN] ;
char c[MAXN] , cc[MAXN] ;
int main(){
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> n ;
    for(i=1;i<=n;i++){
        cin >> a[i] >> c[i] ;
        L += a[i] ;
    }
    for(i=1;i<=n;i++){
        aa[i] = a[n-i+1] ;
        cc[i] = c[n-i+1] ;
    }
    while(i1<=n && i2<=n && cnt<L/2){
        if(c[i1]==cc[i2]){
            if(a[i1]==aa[i2]){
                cnt += a[i1] ;
                i1++ ;
                i2++ ;
            }else if(a[i1]<aa[i2]){
                cnt += a[i1] ;
                aa[i2] -= a[i1] ;
                i1++ ;
            }else if(a[i1]>aa[i2]){
                cnt += aa[i2] ;
                a[i1] -= aa[i2] ;
                i2++ ;
            }
        }else {
            if(a[i1]==aa[i2]){
                ans += a[i1] ;
                cnt += a[i1] ;
                i1++ ;
                i2++ ;
            }else if(a[i1]<aa[i2]){
                cnt += a[i1] ;
                ans += a[i1] ;
                aa[i2] -= a[i1] ;
                i1++ ;
            }else if(a[i1]>aa[i2]){
                cnt += aa[i2] ;
                ans += aa[i2] ;
                a[i1] -= aa[i2] ;
                i2++ ;
            }
        }
    }
    cout << ans ;
    return 0 ;
}
//J组也有人做迷惑行为吗
//CcF.
