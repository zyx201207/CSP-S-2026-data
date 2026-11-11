#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll read(){
    ll x=0,f=1;char p=getchar();
    while(!isdigit(p)){if(p=='-')f=-1;p=getchar();}
    while(isdigit(p))x=x*10+p-'0',p=getchar();
    return x*f;
}
int n,p,ans;ll m,a[N],sum;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum+=a[i];
        while(a[i]*(i-p)-sum>m)sum-=a[++p];
        ans=max(ans,i-p);
    }
    printf("%d",ans);
    return 0;
}