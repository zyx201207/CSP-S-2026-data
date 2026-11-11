#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0') {if(ch=='-') f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0') {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=5e5+5;
int n,m,a[N];
signed main(){
    freopen("crystal.in" ,"r",stdin );
    freopen("crystal.out","w",stdout);
    // freopen("1.in" ,"r",stdin );
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    queue<int> q;int sum=0,num=0,ans=0;
    for(int i=1;i<=n;i++) {
        q.push(a[i]);sum+=a[i],num++;
        while(!q.empty()&&num*a[i]-sum>m) {num--;sum-=q.front();q.pop();}
        ans=max(ans,num);
    }
    printf("%lld\n",ans);
    return 0;
}