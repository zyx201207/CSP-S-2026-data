//I AK CSP-J
// 100 + 100 + 100 + 100 = 400

#include<bits/stdc++.h>
using namespace std;

inline void solve(){
    int n;cin>>n;
    vector<pair<int,char>> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    long long ans=0;
    int l=1,r=n;
    while(l<r){
        if(a[l].second==a[r].second){
            if(a[l].first==a[r].first) l++,r--;
            else if(a[l].first<a[r].first) a[r].first-=a[l].first,l++;
            else a[l].first-=a[r].first,r--;
        }else{
            if(a[l].first<a[r].first) ans+=a[l].first,a[r].first-=a[l].first,l++;
            else ans+=a[r].first,a[l].first-=a[r].first,r--;
        }
    }
    cout<<ans<<endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    solve();
    return 0;
}

