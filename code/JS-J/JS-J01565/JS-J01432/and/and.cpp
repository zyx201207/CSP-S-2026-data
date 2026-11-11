#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200000],ans;
bool b[20];
void dfs(long long x,int l,int d)
{
    if(d==m)
    {
        ans=max(ans,x);
    }
    for(int i=l;i<n-m+x+1;i++)
    {
        if(!b[i])
        {
            b[i]=1;
            dfs(x&a[i],i+1,d+1);
            b[i]=0;
        }
    }
    return;
}
void case1()
{
    for(int i=0;i<n-m+1;i++)
    {
        dfs(a[i],i+1,1);
    }
    cout<<ans;
    return;
}
void case2()
{
    sort(a,a+n);
    cout<<a[n-1];
    return;
}
void case3()
{
    ans=a[0];
    for(int i=1;i<n;i++)
    {
        ans&=a[i];
    }
    cout<<ans;
    return;
}
void case4()
{
    for(int i=0;i<n;i++)
    {
        for(int l=i+1;l<n;l++)
        {
            ans=max(ans,a[i]&a[l]);
        }
    }
    cout<<ans;
    return;
}
void case5()
{
    long long x;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            x=a[1];
        }
        else
        {
            x=a[0];
        }
        for(int l=1;l<n;l++)
        {
            if(l!=i)
            {
                x&=a[l];
            }
        }
        ans=max(ans,x);
    }
    cout<<ans;
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n<=20)
    {
        case1();
    }
    else if(n<=2000)
    {
        if(m==1)
        {
            case2();
        }
        else if(m==n)
        {
            case3();
        }
        else
        {
            case4();
        }
    }
    else
    {
        if(m==n-1)
        {
            case5();
        }
    }
    return 0;
}
