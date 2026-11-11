#include<bits/stdc++.h>
#define ll long long
#define il inline
#define gc getchar
#define pc putchar
using namespace std;
int read_int()
{
    int x=0,y=1;
    char ch=gc();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')y=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=gc();
    }
    return x*y;
}
ll read_ll()
{
    ll x=0,y=1;
    char ch=gc();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')y=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=gc();
    }
    return x*y;
}
void write_int(int x)
{
    if(x<0)
    {
        x=-x;
        pc('-');
    }
    if(!x)
    {
        pc('0');
        return;
    }
    char st[20];
    int tot=0;
    while(x)
    {
        st[++tot]=x%10+48;
        x/=10;
    }
    while(tot)pc(st[tot--]);
}
void write_ll(ll x)
{
    if(x<0)
    {
        x=-x;
        pc('-');
    }
    if(!x)
    {
        pc('0');
        return;
    }
    char st[20];
    int tot=0;
    while(x)
    {
        st[++tot]=x%10+48;
        x/=10;
    }
    while(tot)pc(st[tot--]);
}
const int N=5e5+5;
int n;
ll m,a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read_int();
    m=read_ll();
    for(int i=1;i<=n;i++)a[i]=read_ll();
    ll ans=1;
    sort(a+1,a+1+n);
    priority_queue<ll,vector<ll>,greater<ll> >q;
    for(int i=1;i<n;i++)
    {
        ll d=a[i+1]-a[i];
        if(m>=d*ans)
        {
            m-=d*ans;
            ans++;
            q.push(a[i]);
        }
        else
        {
            ll x=q.top();
            q.pop();
            ll dd=a[i]-x;
            q.push(a[i]);
            m=m+dd-d*ans;
        }
    }
    write_ll(ans);
    return 0;
}