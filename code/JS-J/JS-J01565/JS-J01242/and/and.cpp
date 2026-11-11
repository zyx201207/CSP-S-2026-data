#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
const int N=200010;
int ans;
int n,m;
int a[N];
pii t[N];
bool cmp(pii x,pii y)
{
    return x.second > y.second;
}

void dfs(int k,int cnt,int number)
{
    if(k>n)
        return;
    if(cnt==m)
    {
        if(ans==0)
            ans=number;
        else
            ans=max(ans,number);
        return;
    }
    if(number==-1)
        dfs(k+1,cnt+1,a[k]);
    else
        dfs(k+1,cnt+1,number&a[k]);
    dfs(k+1,cnt,number);
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    a[0]=-1;
    cin>>n>>m;
    bool flag1=1,flag2=1,flag3=1;
    double pd1=log2(n);
    int pd2=log2(n);
    if(pd1!=pd2)
        flag2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        double lg1=log2(a[i]+1);
        int lg2=log2(a[i]+1);
        if(lg1!=lg2)
            flag1=0;
        if(a[i]!=a[i-1]+1)
            flag2=0;
        if(a[i]>=4)
            flag3=0;
    }

    if(m==1)
    {
        ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,a[i]);
        cout<<ans;
        return 0;
    }
    if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
            ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
        cout<<ans;
        return 0;
    }
    if(flag1)
    {
        sort(a+1,a+1+n);
        ans=a[n-m+1];
        cout<<ans;
        return 0;
    }
    if(flag2)
    {
        ans=n-1;
        for(int i=n-2;i>=n-m;i--)
            ans=ans&i;
        cout<<ans;
        return 0;
    }
    if(flag3)
    {
    int ii=1;
    for(int i=1;i<=n;i++)
    {
        long long q=0;
        int p=a[i];
        int B=1;
        while(p)
        {
            q=q+(p%2)*B;
            B*=2;
            p/=2;
        }
        t[ii].first=a[i];
        t[ii].second=q;
        ii+=1;
    }
    sort(t+1,t+ii,cmp);
    ans=t[1].first;
    for(int i=2;i<=m;i++)
        ans=ans&t[i].first;
    cout<<ans;
    return 0;
    }
    dfs(0,0,-1);
    cout<<ans;
    return 0;
}
