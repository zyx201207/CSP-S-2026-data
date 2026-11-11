#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s = "0";
char c;
ll n,a[200005],L = 0,ans = 0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(ll i = 1;i <= n;i++){
        cin >> a[i] >> c;
        L += a[i];
        for(ll j = a[i];j >= 1;j--){
            s += c;
        }
    }
    for(ll i = 1;i <= (L+1)/2;i++){
        if(s[i] != s[L-i+1]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
