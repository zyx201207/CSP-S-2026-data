#include <bits/stdc++.h>
#define ll long long
#define isok cout << "ok" << endl
#define DB(s,a) cout << s << ":" << a << endl
using namespace std ;
const ll MAXN = 200005 ;
ll n , m , i , t , l , r , mid , ans , a[MAXN] , vis[MAXN] ;
string s , b[MAXN] ;
bool check(ll x){
    string str ;
    ll t , cnt , len ;
    memset(vis,true,sizeof(vis)) ;
    vector<string> v ;
    str.clear() ;
    t = x ;
    while(t){
        str.push_back(t%2+'0') ;
        t /= 2 ;
    }
    for(ll j=29;j>str.size()-1;j--){
        cnt = 0 ;
        for(ll i=1;i<=n;i++){
            cnt += b[i][j]-'0' ;
        }
        if(cnt>=m){
            return true ;
        }
    }
    cnt = 0 ;
    for(ll i=1;i<=n;i++){
        cnt += b[i][str.size()-1]-'0' ;
    }
    if(cnt<m){
        return false ;
    }
    if(cnt>=m){
        for(ll i=1;i<=n;i++){
            if(b[i][str.size()-1]=='1'){
                v.push_back(b[i]) ;
            }
        }
        len = v.size() ;
        for(ll i=str.size()-2;i>=0;i--){
            if(str[i]=='0'){
                cnt = 0 ;
                for(ll j=0;j<len;j++){
                    if(!vis[j]){
                        continue ;
                    }
                    if(v[j][i]=='1'){
                        cnt++ ;
                    }
                }
                if(cnt>=m){
                    return true ;
                }
            }else {
                cnt = 0 ;
                for(ll j=0;j<len;j++){
                    if(!vis[j]){
                        continue ;
                    }
                    if(v[j][i]=='0'){
                        vis[j] = false ;
                    }else {
                        cnt++ ;
                    }
                }
                if(cnt<m){
                    return false ;
                }
            }
        }
    }
    return true ;
}
int main(){
    freopen("and.in","r",stdin) ;
    freopen("and.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> n >> m ;
    for(i=1;i<=n;i++){
        cin >> a[i] ;
        r = max(r,a[i]) ;
    }
    for(i=1;i<=n;i++){
        s.clear() ;
        t = a[i] ;
        while(t){
            s.push_back(t%2+'0') ;
            t /= 2 ;
        }
        while(s.size()<=30){
            s.push_back('0') ;
        }
        b[i] = s ;
    }
    while(l<=r){
        mid = (l+r) >> 1 ;
        if(check(mid)){
            l = mid+1 ;
            ans = mid ;
        }else {
            r = mid-1 ;
        }
    }
    cout << ans ;
    return 0 ;
}
//我不知道我还要参加的意义是什么
//不是说好的退役吗
//三年来连个J 1=都没有
//还有必要吗？
//可还是放不下啊......
//OI你个臭杂鱼
