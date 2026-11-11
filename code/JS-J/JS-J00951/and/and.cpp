#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
const int maxk=30;
int n,m;
int a[maxn];
bool dp[maxn][maxk];
int ans=0;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,0,sizeof(dp));
    cin>>n>>m;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i){
        int t=a[i],p=30;
        while(t&&--p>=0){
            if(t&1) dp[i][p]=1;
            t>>=1;
        }
    }
    set<int> s;
    for(int i=0;i<n;++i) s.insert(i);
    for(int i=0;i<maxk;++i){
        set<int> s2;
        for(int j=0;j<n;++j) if(s.count(j)&&dp[j][i]) s2.insert(j);
        if((int)s2.size()>=m) s=move(s2);
        if((int)s2.size()==m) break;
    }
    int cnt=0;
    for(auto i:s){
        if(cnt==0) ans=a[i];
        else ans&=a[i];
        if(++cnt==m) break;
    }
    cout<<ans<<'\n';
    return 0;
}