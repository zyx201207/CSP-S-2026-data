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


const int N=2e6+3;
__int128 c[N],n,a[N],T,d,f[N];
bool tsa;
void plana()
{
    if(d<c[2]*2)    write(0,1);
    else    write(max(n-2*(d/c[2])+1,(__int128)0),1);
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    T=read();T=read();
    while(T--)
    {
        tsa=true;
        n=read();d=read();
        for(int i=1;i<=n;i++)   f[i]=0;
        //write(n,1);
        for(int i=1;i<=n;i++)   a[i]=read();
        /*if(n<=10)
        {
            for(int i=1;i<=n;i++)
            {
                write(a[i],0);
            }
            cout<<'\n';
        }*/
        if(n<=1)
        {
            write(0,1);
            continue;
        }
        for(int i=2;i<=n;i++)   c[i]=a[i]-a[i-1];
        for(int i=3;i<=n;i++)
        {
            if(c[i]!=c[i-1])
            {
                tsa=false;
                break;
            }
        }
        //for(int i=2;i<=n;i++)   write(c[i],0);
        //write(d,1);
        //rite(c[2],1);
        if(tsa) plana();
        else{
            __int128 sum=0;
            for(int i=n;i>=1;i--)
            {
                long long idx=upper_bound(a+1,a+1+n,d+a[i])-a;
                idx--;
                f[idx]++;
            }
            for(int i=1;i<=n;i++)
            {
                long long idx=upper_bound(a+1,a+1+n,d+a[i])-a;
                idx--;
                idx--;
                if(idx<=i||idx>=n)  continue;
                long long idx2=upper_bound(a+1,a+1+n,d+a[idx])-a;
                long long idx3=upper_bound(a+1,a+1+n,d+a[idx-1])-a;
                idx2--;
                idx3--;
                sum+=(idx2-idx3)*(f[i]+1);
                //cout<<i<<' '<<idx<<' '<<idx2<<' '<<idx3<<' ';
                //write(sum,1);
            }
            write(sum,1);
        }
    }
    return 0;
}
