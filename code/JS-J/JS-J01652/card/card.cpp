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
    freopen("card.in","r",stdin) ;
    freopen("card.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    for(ll i=1;i<=114514;i++){
        cout << 6767 ;
    }
    return 0 ;
}
//部分分不想打了
//不过好在这次发挥还行
//100+100+100+0=300pts
//打完下午的S组就退役吧
//初三太累了
/*
我也难过这beat越顶
众人皆醉我独醒
我看透了人心百毒不侵
却再看不清那张合影
我的心大部分是冰的
曾经跟死神有过一夜情
（这两句忘了）
我在5：20睡觉13：14准时起
*/
//luogu:__Clannad__
