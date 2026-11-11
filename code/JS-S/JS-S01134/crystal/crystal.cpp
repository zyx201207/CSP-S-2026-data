#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10,INF=0x3f3f3f3f,NINF=0xc0c0c0c0;
int n,m,maxn,x,a[N];

inline int read()
{
    char c=getchar();
    bool sign=0;
    int p=0;
    while(c<'0'||c>'9') sign=(c=='-'),c=getchar();
    while(c>='0'&&c<='9') p=(p<<3)+(p<<1)+c-'0',c=getchar();
    return (sign?-p:p);
}

bool cmp(int a,int b)
{
    return abs(a-x)<abs(b-x);
}

signed main()
{
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    n=read(),m=read();
    int k;
    bool f=1,f1=1;
    for(int i=1;i<=n;i++)
    {
        a[i]=read(),maxn=max(a[i],maxn);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(!(a[i]==i)) f=0;
        if(i==2) k=a[i]-a[i-1];
        else if(a[i]-a[i-1]!=k) f1=0;
    }
    int ans=0;
    if(f)
    {
        int x=0;
        for(int i=1;i<=n;i++)
        {
            if(m>=i*(i+1)/2) ans=i+1;
            else break;
        }
        cout<<ans;
        return 0;
    }
    if(f1)
    {
        for(int i=1;i<=n;i++)
        {
            if(m>=k*i*(i+1)/2) ans=i+1;
            else break;
        }
        cout<<ans;
        return 0;
    }
    for(x=1;x<=maxn;x++)
    {
        int cnt=0,p=0;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            cnt+=abs(a[i]-x);
            if(cnt>m) break;
            p++;
        }
        ans=max(ans,p);
    }
    cout<<ans;
    return 0;
}

