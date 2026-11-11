#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,l,r;
pair<ll,char> a[N];
ll ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    l=1;
    r=n;
    while(l<r){
        ll minn=min(a[l].first,a[r].first);
        a[l].first-=minn;
        a[r].first-=minn;
        if(a[l].second!=a[r].second){
            ans+=minn;
        }
        if(a[l].first==0){
            l++;
        }
        if(a[r].first==0){
            r--;
        }
    }
    cout<<ans;
    return 0;
}
