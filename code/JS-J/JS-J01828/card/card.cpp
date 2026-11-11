#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int ans[N];
vector<int> sta;
signed main(void){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            for(int k=0;k<sta.size();++k) if(a[j]==sta[k]){
                while(sta.size()>k) sta.pop_back();
                break;
            }
            sta.push_back(a[j]);
        }
        for(int x:sta) ++ans[x];
        sta.clear();
    }
    for(int i=1;i<=m;++i) cout<<ans[i]<<' ';
    return 0;
}
