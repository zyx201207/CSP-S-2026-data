#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
ll n,ans,l;
map<ll,pair<ll,char>> a;//l,r,data
map<ll,pair<ll,char>> b;//r,l,data

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=0;i<n;i++){
        ll x;char c; cin>>x>>c;
        a[l]={l+x,c};
        b[l+x]={l,c};
        l+=x;
    }
    for(ll i=0,j=l;i<j;){
        if(a[i].second!=b[j].second)
            ans+=abs(min(a[i].first,l-b[j].first)-max(i,l-j));
        if(a[i].first>l-b[j].first)
            j=b[j].first;//j--
        else if(a[i].first==l-b[j].first)
            i=a[i].first,j=b[j].first;
        else
            i=a[i].first;//i++
        // cout<<i<<' '<<j<<' '<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}