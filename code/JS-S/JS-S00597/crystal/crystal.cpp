#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define mk make_pair
using namespace std;
#define int long long
int read()
{
    char c=getchar(); int ret=0,f=1;
    while(c<48||c>57){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>=48&&c<=57)ret=ret*10+c-48,c=getchar();
    return ret*f;
}
#define N 600500
int n,m,a[N],Ans,p,u;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(); m=read();
    F(i,1,n)a[i]=read();
    sort(a+1,a+n+1); Ans=1;
    u=1; p=0;
    F(i,2,n){
        p += (i-u)*(a[i]-a[i-1]);
        while(p>m){
            p-=(a[i]-a[u]);
            ++u;
        }
        Ans=max(Ans,i-u+1);
    }
    printf("%lld\n",Ans);
}