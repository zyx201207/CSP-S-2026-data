#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    ll l=1,r=n,ans=0;
    while(l<r){
        ll idx=min(a[l],a[r]);
        if(c[l]!=c[r]){
            ans+=idx;
        }
        a[l]-=idx;
        a[r]-=idx;
        if(a[l]==0)l++;
        if(a[r]==0)r--;
    }
    cout<<ans;
    return 0;
}
