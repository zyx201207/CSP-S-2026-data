#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define MANX MAXN
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
namespace ylf{ void cat(); }
// 14:54 passed
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int T=1;
    // cin>>T;
    while(T--) ylf::cat();
    return 0;
}

namespace ylf{
    int a[MAXN],pre[MAXN];
    int n,m;
    int asum(int l,int r){
        return pre[r]-pre[l-1];
    }
    bool check(int len){
        int cost=LLONG_MAX;
        for(int r=len;r<=n;r++){
            int l=r-len+1;
            int sum=asum(l,r);
            int need=a[r]*len;
            cost=min(cost,need-sum);
        }
        return cost<=m;
    }
    void cat(){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
        int lo=1,hi=n+1;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(check(mid)) lo=mid+1;
            else hi=mid;
        }
        cout<<lo-1;
    }
}