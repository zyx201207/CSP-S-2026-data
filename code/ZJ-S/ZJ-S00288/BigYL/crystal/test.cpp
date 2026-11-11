#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define debug1(x) cerr<<(#x)<<"="<<(x)<<" "
#define debug2(x) cerr<<(#x)<<"="<<(x)<<"\n"
template<class T>
inline void operator += (vector<T>&x,const T &y){x.emplace_back(y);}
namespace ARIS2_0{
    constexpr int maxn=5e5+10;
    ll a[maxn],s[maxn];
    void solve(){
        int n;ll m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
        int z=0,ans=0;
        //前缀 [1,z] 不能转化
        for(int i=1;i<=n;i++){
            if(i<n and a[i]==a[i+1])continue;
            //以 i 为基准
            //代价是，(i-z) * a[i] - [z+1,i] 的和
            while((i-z)*a[i]-(s[i]-s[z])>m)z++;
            ans=max(ans,i-z);
        }
        cout<<ans<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)ARIS2_0::solve();
}