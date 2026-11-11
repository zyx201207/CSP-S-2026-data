#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e5+7;
pair<int,char>a[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i].first >> a[i].second;
    int l=1,r=n,ans=0;
    while(l<r){
        if(a[l].second!=a[r].second){
            ans+=min(a[l].first,a[r].first);
        }
        a[l].first-=min(a[l].first,a[r].first);
        a[r].first-=min(a[l].first,a[r].first);
        if(a[l].first==0) l++;
        if(a[r].first==0) r--;
    }
    cout << ans;
    return 0;
}
