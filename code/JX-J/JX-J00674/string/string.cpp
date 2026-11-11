#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#define ll long long
#define CSP2026 using
#define plus_plus namespace std
#define debug cout << "check" << endl;
CSP2026 plus_plus;
ll n,ans,l = 1,r;
struct NODE{
    ll a;
    char c;
}h[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1;i <= n;i++){
        cin >> h[i].a >> h[i].c;
    }
    r = n;
    while(l < r){
        ll num = min(h[l].a,h[r].a);
        //cout << num << endl;
        if(h[l].c != h[r].c){
            ans += num;
        }
        h[l].a -= num;
        h[r].a -= num;
        //cout << l << " " << h[l].a << endl;
        //cout << r << " " << h[r].a << endl;
        if(h[l].a == 0)
            l++;
        if(h[r].a == 0)
            r--;
        //cout << l << " " << r << endl << ans << endl << endl;
    }
    cout << ans;
    return 0;
}
