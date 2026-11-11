#include <bits/stdc++.h>
#define gc() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin))),*p1++)
using ll=long long;
using namespace std;
char buf[1<<20],*p1,*p2;
ll read(){
    ll s=0,f=1,c=gc();
    for(;!isdigit(c);c=gc()) if(c=='-') f=-1;
    for(;isdigit(c);c=gc()) s=s*10+(c^48);
    return s*f;
}
const int N=5e5+10;
deque<ll> q;
ll a[N];
ll n,m,sum,ans;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int s=a[i];
        if(!q.empty())
            sum+=q.size()*(s-q.back());
        while(!q.empty()&&sum>m){
            sum-=(s-q.front());
            q.pop_front();
        }
        q.push_back(s);
        ans=max(ans,(ll)q.size());
    }
    cout<<ans;
    return 0;
}
