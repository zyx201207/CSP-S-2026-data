#include<bits/stdc++.h>
#define ll long long
using namespace std;
int const N=100000;
ll n,a[2*N+10];
char c[2*N+10];
ll L,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
        for(ll j=1;j<=a[i];j++){
            s=s+c[i];
        }
    }
    for(ll i=1;i<=L;i++){
        if(s[i]!=s[L+1-i]){
            s[i]=s[L+1-i];
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
