#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==n)
    {
        int ans=a[1];
        for(int i=1;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        int maxn=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    if(m==2)
    {
        int maxn=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n-1)
    {
        int maxn=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            int k=1;
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    k&=a[j];
                }
            }
            maxn=max(k,maxn);
        }
        cout<<maxn;
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    int ans=a[1];
    for(int i=1;i<=m;i++)
    {
        ans&=a[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

