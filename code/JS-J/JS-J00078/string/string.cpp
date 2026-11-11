#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+16;
int a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
    }
    ll ans=0;
    for(int i=1,j=n,mn;i<j;a[i]?--j:++i){
        mn=min(a[i],a[j]);
        a[i]-=mn;
        a[j]-=mn;
        if(c[i]^c[j]){
            ans+=mn;
        }
    }
    cout<<ans;
    return 0;
}