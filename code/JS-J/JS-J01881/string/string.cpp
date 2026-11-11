#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
struct block{
    ll l,r;
    char c;
}a[N];
int n;
ll pos=0,rpos,sum=0,ans=0,step;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int len;
        scanf("%d%c%c",&len,&a[i].c,&a[i].c);
        a[i].l=sum+1;
        sum=a[i].r=sum+len;
    }rpos=sum+1;
    int il=1,ir=n;
    while(il<ir){
        step=min(a[il].r-pos,rpos-a[ir].l);
        pos+=step,rpos-=step;
        if(a[il].c!=a[ir].c)ans+=step;
        if(pos==a[il].r)il++;
        if(rpos==a[ir].l)ir--;
    }printf("%lld",ans);
    return 0;
}