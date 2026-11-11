#include <bits/stdc++.h>
#define int long long

using namespace std;

int read()
{
    int tot=0,f=1;
    char ch=getchar();
    while(ch!='-'&&(ch>'9'||ch<'0'))
        ch=getchar();
    if(ch=='-')
        f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')
        tot=tot*10+(ch-'0'),ch=getchar();
    return tot*f;
}

int myabs(int x)
{
    if(x>0)
        return x;
    return -x;
}

const int maxn=5e5+10;
int n,m,ans=0,a[maxn];

bool check(int len)
{
    if(len==1)
        return 1;
    queue <int> q;
    int tot=0;
    for(int i=1;i<=len;i++)
    {
        q.push(a[i]);
        tot+=a[i];
    }
    if(a[len]*len-tot<=m)
        return 1;
    for(int i=2;i+len-1<=n;i++)
    {
        q.pop();
        tot-=a[i-1];
        int j=i+len-1;
        q.push(a[j]);
        tot+=a[j];
        if(a[j]*len-tot<=m)
            return 1;
    }
    return 0;
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    int l=1,r=n;
    int ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<ans<<'\n';
    return 0;
}
