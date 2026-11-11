#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
#define pii pair<int,int> 
#define popc __builtin_popcount
#define All(v) (v).begin(),(v).end()
#define lowbit(x) ((x)&(-(x)))
const int inf=1e9;
const int N=1e6+5;
int n,dis[N],res,k;
vector<int> a[N];
inline ll read(){
    ll x(0),t(0);
    static char ch=getchar();
    while(!isdigit(ch)) t|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t?-x:x;
}
int is[N];
inline void work(){
    n=read();k=read();
    for(int i=1;i<=n;i++) a[i].clear();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        a[x].emplace_back(y);
        a[y].emplace_back(x);
    }
    res=inf;
    if(n<=20){
    for(int S=0;S<1<<n;S++){
        if(popc(S)!=k) continue;
        int cnt=k;
        for(int i=0;i<n;i++){
            if(S>>i&1)
            for(int j:a[i+1]) if(j>i+1) if(S>>j-1&1) cnt--;
        }
        if(cnt>2) continue;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(S>>i&1) q.emplace(i+1),dis[i+1]=0;
            else dis[i+1]=inf;
        }
        while(q.size()){
            int x=q.front();q.pop();
            for(int y:a[x]){
                if(dis[y]>dis[x]+1){
                    q.emplace(y);
                    dis[y]=dis[x]+1;
                }
            }
        }
        res=min(res,*max_element(dis+1,dis+1+n));
    }
    cout<<res<<'\n';
    return;
    }
    else{
        if(k==n){
            cout<<0<<'\n';
            return;
        }
        auto check=[&](int lim)->bool {
            int len=n+1>>1;
            if(lim+lim*2+k+lim-1>=len) return 1;
            return 0;
        };
        int l=1,r=n-1;
        while(l<r){
            int mid=l+r>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        cout<<r<<'\n';
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int _=read();
    int t=read();
    while(t--) work();
    return 0;
}
// Oct31==Dec25?