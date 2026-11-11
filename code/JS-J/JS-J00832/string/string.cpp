#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+5;
ll n;
ll a[N];
char c[N];
string s,s1,s2;
ll k,sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(ll i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(ll j=0;j<a[i];j++)
            s+=c[i];
        k+=a[i];
    }
    k/=2;
    for(ll i=0;i<k;i++){
        s1+=s[i];
        s2+=s[s.size()-1-i];
    }

    for(ll i=0;i<k;i++){
        if(s1[i]!=s2[i]) sum++;
    }

    cout<<sum;
    return 0;
}
