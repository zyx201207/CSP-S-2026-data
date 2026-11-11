#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m,a[N],b[35],c[35],d[35],sum=1,cnt=1,p,ans=INT_MAX;
bool cmp(int a,int b)
{
    return a>b;
}
void er(int s)
{
    memset(b,0,sizeof(b));
    sum=1;
    while(s>0)
    {
        b[sum]=s%2;
        sum++;
        s/=2;
    }
}
void er1(int s)
{
    memset(c,0,sizeof(c));
    cnt=1;
    while(s>0)
    {
        c[cnt]=s%2;
        cnt++;
        s/=2;
    }
}
void shi()
{
    p=0;
    for(int i=1;i<=min(cnt,sum);i++)
    {
        int j=i;
        while(j>1)
        {
            d[i]*=2;
            j--;
        }
        p+=d[i];
    }
}
int yu(int x,int y)
{
    er(x);
    er1(y);
    memset(d,0,sizeof(d));
    for(int i=1;i<=max(cnt,sum);i++)
    {
        if(b[i]==c[i])    d[i]=b[i];
        else    d[i]=0;
    }
    shi();
    return p;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1)
    {
        cout<<a[1];
        exit(0);
    }
    if(a[1]<4)
    {
        for(int i=1;i<=min(n,m);i++)
        {
            ans=min(ans,a[i]);
        }
        cout<<ans;
        exit(0);
    }
    for(int i=1;i<m;i++)
    {
        a[i]=yu(a[i],a[i+1]);
    }
    cout<<a[m-1];
    return 0;
}
