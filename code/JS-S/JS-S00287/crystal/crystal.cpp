#include<bits/stdc++.h>
using namespace std;
long long read()
{
    long long x=0;
    short f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')  f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
void wit(long long x)
{
    if(x<=9)    putchar(x+'0');
    else{
        wit(x/10);
        putchar(x%10+'0');
    }
}
void write(long long x,bool enld)
{
    if(x>=0)    wit(x);
    else{
        putchar('-');
        wit(-x);
    }
    if(enld)    putchar('\n');
    else    putchar(' ');
}

const int N=5e5+13;
__int128 n,m,ans=1,a[N],pre[N];
bool check(long long idx,long long i)//no qu idx
{
    if(a[i]*(i-idx)<=pre[i]-pre[idx]+m) return true;
    else    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)   a[i]=read();
    sort(a+1,a+1+n);
    //for(int i=1;i<=n;i++)   write(a[i],1);
    for(int i=1;i<=n;i++)   pre[i]=pre[i-1]+a[i];
    //for(int i=1;i<=n;i++)   write(pre[i],1);
    for(int i=1;i<=n;i++)
    {
        __int128 nw;
        long long l=0,r=i-1;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(check(mid,i))
            {
                r=mid-1;
                nw=mid;
            }
            else    l=mid+1;
        }
        ans=max(ans,i-nw);
        //write(i-nw,1);
    }
    write(ans,1);
    return 0;
}
