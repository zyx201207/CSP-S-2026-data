#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500010;
ll n,m,ans;
ll a[maxn],dis[maxn],c[maxn],sum[maxn],sum2[maxn];

inline ll read(){
    ll s=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}

ll lowbit(ll x){
    return x & (-x);
}

bool cmp(ll x,ll y){
    return x>y;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1,cmp);
    for(int i=2;i<=n;i++){
        dis[i]=a[i-1]-a[i];
        for(int x=i;x<=n;x+=lowbit(x)){
            c[x]+=dis[i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int x=i;x>=1;x-=lowbit(x)){
            sum[i]+=c[x];
        }
    }
    for(int i=1;i<=n;i++){
       	sum2[i]=sum[i]+sum2[i-1];
    }
    
    int tail=2;
    for(int i=1;i<=n;i++){
        while(tail<=n){
            ll cost=(sum2[tail]-sum2[i])-sum[i]*(tail-i+1);
            if(cost>m) break;
            tail++;
        }
        ll cnt=tail-i;
        ans=max(cnt,ans);
    }
    
    printf("%lld",ans);
    return 0;
}