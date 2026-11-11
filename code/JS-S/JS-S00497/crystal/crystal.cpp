#include<bits/stdc++.h>
#define int long long
#define rg register
using namespace std;
const int N=500000+10;
int n,m,ans=1;
int a[N];
bool f=true;
int rd(){
    int si=1,x=0;
    char c;
    for(c=getchar();c<'0'||c>'9';c=getchar())
        if(c=='-')si=-1;
    for(;c>='0'&&c<='9';c=getchar())
        x=(x<<1)+(x<<3)+(c^48);
    return x*si;
}
void fre(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
}
void work(){
    n=rd();m=rd();
    for(rg int i=1;i<=n;i++){
        a[i]=rd();
        if(a[i]<a[i-1])f=false;
    }
    if(!f)sort(a+1,a+1+n);
    for(rg int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    for(rg int i=n;i>1;i--){
        for(rg int j=0;j<i;j++){
            if(ans>=i-j)break;
            if((i-j)*(a[i]-a[i-1])-a[i]+a[j]<=m){
                ans=i-j;
                break;
            }
        }
    }
    printf("%lld",ans);
}
signed main()
{
  fre();
    work();
    return 0;
}
