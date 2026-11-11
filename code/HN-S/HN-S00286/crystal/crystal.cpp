// crystal
#include<bits/stdc++.h>
using namespace std;
namespace FASTIO{
    template<typename T>
    void read(T &x){
        x=0;bool f=1;int ch=getchar();
        for(;!isdigit(ch);ch=getchar())f=ch=='-'?0:f;
        for(; isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
        x=f?x:-x;
    }
    void read(){}
    template<typename T,typename ...Args>
    void read(T &x,Args &...args){read(x),read(args...);}
}
namespace Solve{
using FASTIO::read;
constexpr int N=5e5+5;
using ll=long long;
int n,ans;ll m,a[N],s[N];
int main(){
    read(n,m);
    for(int i=1;i<=n;++i)read(a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;++i){
        int l=1,r=i,mid;
        while(l<r){
            mid=l+r>>1;
            if(1ll*(i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    printf("%d\n",ans);
    return 0;
}
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    return Solve::main();
}