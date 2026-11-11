#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int> v,w;
int cnt[31];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        int x;
        cin>>x;
        v.push_back(x);
    }
    if(n<=20){
        int ans=0;
        for (int i=1;i<(1<<n);++i){
            if(__builtin_popcount(i)!=m) continue;
            int cur=INT_MAX;
            for (int j=0;j<n;++j)
                if((i>>j)&1) cur&=v[j];
            ans=max(ans,cur);
        }
        cout<<ans;
        return 0;
    }
    int lst=31;
    while(lst>=0){
        // cerr<<lst<<"\n";
        for (int i=lst-1;i>=0;--i)
            cnt[i]=0;
        for (int x : v)
            for (int i=lst-1;i>=0;--i)
                if((x>>i)&1) ++cnt[i];
        int f=-1;
        for (int i=lst-1;i>=0;--i)
            if(cnt[i]>=m){
                f=i;
                break;
            }
        if(f==-1){
            --lst;
            continue;
        }
        lst=f;
        w.clear();
        for (int x : v)
            if((x>>f)&1) w.push_back(x);
        v=w;
    }
    int ans=INT_MAX;
    for (int x : v)
        ans&=x;
    cout<<ans;
    return 0;
}