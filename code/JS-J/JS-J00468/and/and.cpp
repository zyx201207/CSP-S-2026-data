#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,maxn;
int bl[21];

bool found(int x)
{
    if(x==0 || x==1)
    {
        return true;
    }
    for(int i=0;i<=20;i++)
    {
        if(x+1==bl[i])
        {
            return true;
        }
    }
    return false;
}

bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(found(a[i])==0)
        {
            return false;
        }
    }
    return true;
}

void dfs(int x,int val,int choose)
{
    if(x==n+1)
    {
        if(choose==m)
        {
            maxn=max(maxn,val);
        }
    }
    else
    {
        if(val==-1)
        {
            dfs(x+1,a[x],choose+1);
        }
        else
        {
            dfs(x+1,val&a[x],choose+1);
        }
        dfs(x+1,val,choose);
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bl[0]=1;
    for(int i=1;i<=20;i++)
    {
        bl[i]=bl[i-1]*2;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        sort(a+1,a+n+1,greater<int>());
        cout<<a[1];
    }
    else if(m==2)
    {
        int ans=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    ans=max(ans,(a[i]&a[j]));
                }
            }
        }
        cout<<ans;
    }
    else if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(check())
    {
        sort(a+1,a+n+1,greater<int>());
        cout<<a[m];
    }
    else
    {
        dfs(1,-1,0);
        cout<<maxn;
    }
    return 0;
}
