#include<bits/stdc++.h>
#define int long long
#define rg register
using namespace std;
int c,n,d,t;
int a[2000010];
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
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
}
void work(){
    c=rd();t=rd();
    while(t--){
        n=rd();d=rd();
        for(rg int i=1;i<=n;i++){
            a[i]=rd();
        }
        if(a[n]-a[n-1]>d)printf("0\n");
        else{
            printf("%lld\n",n-d*2/(a[n]-a[n-1])+1);
        }
    }
}
signed main()
{
  fre();
    work();
    return 0;
}

