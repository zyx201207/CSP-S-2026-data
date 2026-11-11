#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n;
    ll m;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    ll s=0;
    int ans=0;
    for(int i=0,p=0;i<n;i++){
        s+=a[i];
        while((i-p+1)*a[i]-s>m)s-=a[p++];
        ans=max(ans,i-p+1);
    }
    cout<<ans<<endl;
    return 0;
}