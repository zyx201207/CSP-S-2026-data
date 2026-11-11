#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int c=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        c=(c<<1)+(c<<3)+ch-48;
        ch=getchar();
    }
    return w*c;
}
#define maxn 555555
int n,m;
int a[maxn];
int qzh[maxn];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    qzh[0]=0;
    for(int i=1;i<=n;i++)qzh[i]=qzh[i-1]+a[i];
    int ans=0;
    for(int i=n;i>0;i--)
    {
        int L=1,R=i,mid;
        while(L<R)
        {
            mid=(L+R)>>1;
            if(a[i]*(i-mid+1)-(qzh[i]-qzh[mid-1])<=m)R=mid;
            else L=mid+1;
            //cout<<L<<" "<<R<<" "<<mid<<endl;
        }
        //cout<<L<<" "<<R<<" "<<mid<<endl;
        ans=max(ans,i-L+1);
    }
    printf("%lld",ans);
    return 0;
}
