#include<bits/stdc++.h>
//Things will always be better, just let time plays
using namespace std;
#define HACKILLER_FAST ios::sync_with_stdio(false),cin.tie(0)
#define int long long
#define ull unsigned long long
#define vc vector
#define pii pair<int,int>
#define pb push_back
#define ls x<<1
#define rs x<<1|1
int n,m,a[500050],s[500050],ans;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    HACKILLER_FAST;
    cin>>n>>m;
    for(int i = 1;i <= n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;++i) s[i] = s[i-1]+a[i];
    for(int i = 1;i <= n;++i){
        if(i == n || a[i] != a[i+1]){
            int l = 1,r = i,res = i;
            while(l <= r){
                int mid = l+r>>1;
                if((i-mid+1)*a[i]-(s[i]-s[mid-1]) <= m) res = mid,r = mid-1;
                else l = mid+1;
            }
            //cerr<<res<<' '<<i<<'\n';
            ans = max(ans,i-res+1);
        }
    }
    cout<<ans;
    return 0;
}
//ForEverLOVE
