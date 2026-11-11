#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,now,sum,a[N],ans;
int read(){
    int k=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
        k=k*10+ch-'0',ch=getchar();
    return k*f;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+1+n);
    now=1;
    for(int i=1;i<=n;i++){
        sum+=(i-now)*(a[i]-a[i-1]);
        while(sum>m&&now<i){
            sum=sum-(a[i]-a[now]);
            now++;
        }
        if(sum<=m)
            ans=max(ans,i-now+1);
    }
    printf("%lld",ans);
    return 0;
}