#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);;
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    multiset<int> s;
    int ans=0;
    for (int i=1;i<=n;i++) s.insert(a[i]);
    for (int j=30;j>=0;j--){
        vector<int> tmp;
        int cnt=0;
        for (auto x:s){
            if ((x>>j)&1){
                cnt++;
                tmp.push_back(x);
            }
        }
        if (cnt>=m){
            s.clear();
            for (int x:tmp) s.insert(x);
            ans+=(1ll<<j);
        }
    }
    cout<<ans;
    return 0;
}
