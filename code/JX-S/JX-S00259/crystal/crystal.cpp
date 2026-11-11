#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll sgn = 1ll ;
    ll res = 0ll ;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')sgn=-sgn;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    res=res*10ll+ch-'0',ch=getchar();
    return res*sgn;
}

const int N=5e5+7;
ll a[N],q[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n=int(read()); ll m=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    sort(a+1,a+n+1);

    int head=1;
    int tail=0;
    ll d=0ll,ans=0ll;
    
    for(int i=1;i<=n;++i){
        q[++tail]=a[i];
        int len=tail-head+1;
        if(len==1){
            d=0ll;
            continue;
        }
        ll eid=q[tail]-q[tail-1];
        d=d+(len-1ll)*1ll*eid;
        while(d>m&&head<=tail){
            d=d-(q[tail]-q[head]);
            head++,len--;
        }
        ans=max(ans,len*1ll);
    }
    cout<<ans<<'\n';

    return 0;
}
