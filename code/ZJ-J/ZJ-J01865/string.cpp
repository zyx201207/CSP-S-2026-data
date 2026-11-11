#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,odd=0;
    ll ans=0;
    cin>>n;
    int p=0,q=n-1;
    vector<ll> a(n);
    vector<char> c(n);
    vector<char> s;
    for (int i=0;i<n;i++) cin>>a[i]>>c[i];
    if (n<2000){
        for (int i=0;i<n;i++){
            for (ll j = 0;j<a[i];j++){
                s.push_back(c[i]);
            }
        }
        int len = s.size();
        for (int i=0;i<(len/2);i++)
        {
            if (s[i]!=s[len-i-1]) ans++;
        }
        cout<<ans;
        return 0;
    }
}
