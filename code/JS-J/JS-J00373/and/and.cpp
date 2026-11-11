#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define pc putchar
using ll=long long;
ll read()
{
    char ch=gc();
    int x=0;
    for(;ch<'0'||ch>'9';ch=gc());
    for(;ch>='0'&&ch<='9';ch=gc()) x=x*10+ch-'0';
    return x;
}
void write(ll x)
{
    if(x>=10) write(x/10);
    pc(x%10+'0');
}
const int N=2e5+5;
int n,m;
ll a[N],ans=LLONG_MAX;
bool taken[N];
bool cmp(ll x,ll y){return x>y;}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1,cmp);
    int ptr=0;
    for(int i=1;i<=m;i++)
    {/*
        if(n-ptr<=m)
        {
            for(int j=ptr+1;j<=n;j++){i++;ans&=a[i];}
            if(i==m) break;
            for(int j=1;j<=n;j++)
            {
                if(!taken[i]) ans&=a[i];
                i++;
                if(i==m) break;
            }
        }*/
        ll delta=LLONG_MAX;
        int pos=0;
        for(int j=ptr+1;j<=n;j++)
        {
            if(ans-(ans&a[j])<delta)
            {
                delta=ans-(ans&a[j]);
                pos=j;
            }
        }
        taken[pos]=true;
        ptr=pos;
        ans-=delta;
    }
    write(ans);
    pc('\n');
}
