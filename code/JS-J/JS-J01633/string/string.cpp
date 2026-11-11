#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , l , ans;
struct node{
    ll v , la;
    char c;
}a[200005];
int main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0) , cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i].v >> a[i].c;
        l += a[i].v;
        a[i].la = a[i].v;
    }
    int lat = n;
    for(ll len = 0 , i = 1 ; len <= l / 2 ; i ++){
        ll xg = 0;
        if(a[i].la != a[i].v){
            cout << ans;
            return 0;
        }
        for(int j = lat ; j >= 1 ; j --){
            if(i == j){
                cout << ans;
                return 0;
            }
            if(xg + a[j].la <= a[i].v){
                xg += a[j].la;
                if(a[i].c != a[j].c){
                    ans += a[j].la;
                }
                a[j].la = 0;
                continue;
            }
            lat = j;
            if(a[i].c != a[j].c){
                ans += a[i].v - xg;
            }
            a[j].la -= a[i].v - xg;
            break;
        }
        len += a[i].v;
    }
    cout << ans;
    return 0;
}