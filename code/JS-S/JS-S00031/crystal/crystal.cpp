#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define pc putchar
using ll=long long;
ll read()
{
    char ch=gc();
    ll x=0,f=1;
    for(;ch<'0'||ch>'9';ch=gc())if(ch=='-') f=-1;
    for(;ch>='0'&&ch<='9';ch=gc()) x=x*10+ch-'0';
    return x*f;
}
void write(ll x)
{
    if(x>=10) write(x/10);
    pc(x%10+'0');
}
const int N=5e5+5;
ll n,m,a[N];
int check(int ptr)
{
    int cnt=0;
    ll total=m;
    while(ptr>0&&a[ptr-1]==a[ptr])  ptr--;
    int standard=a[ptr];
    ptr--;
    //cout<<"seek ptr"<<ptr<<endl;
    while(ptr>0&&total>0)
    {
        if(total>=standard-a[ptr])
        {
            total-=standard-a[ptr];
            cnt++;
            ptr--;
        }
        else
        {
            break;
        }
    }
    return cnt;
}
bool sp1=true,sp2=true;
void process1()
{
    int ans1=(int(sqrt(double(1+8*m+1e-9))-1))/2;
    write(min(ans1*1LL+1LL,n));
    return;
}
void process2()
{
    int delta=a[2]-a[1];
    int ans2=(int(sqrt(double(1)+double(8*m)/double(delta)+1e-9))-1)/2;
    write(min(ans2*1LL+1LL,n));
    return;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        if(a[i]!=i) sp1=false;
        if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) sp2=false;
    }
    if(!sp1) sort(a+1,a+n+1);
    if(sp1)
    {
        process1();
        return 0;
    }
    if(sp2)
    {
        process2();
        return 0;
    }
    int ans=1;
    int cur=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1]) cur++;
        else cur=1;
        if(a[i]==a[i+1]) continue;
        int chk=check(i);
        //cout<<"now is"<<i<<"we have cur"<<cur<<"check"<<chk<<endl;
        ans=max(ans,cur+chk);
    }
    write(ans);
    return 0;
}
