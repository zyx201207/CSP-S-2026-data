#include<bits/stdc++.h>
using namespace std;
int n,m,a[2222],mx=-1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    if(m==1)
    {
        cout<<a[1];
    }
    else if(m==n)
    {
        int x=a[1];
        for(int i=2;i<=n;i++)
        {
            x=x&a[i];
        }
        cout<<x;
    }
    else if(m==2)
    {
        int x=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                x=a[i]&a[j];
                mx=max(mx,x);
            }
        }
        cout<<mx;
    }
    else
    {
        int x=a[1];
        for(int i=2;i<=m;i++)
        {
            x=x&a[i];
        }
        cout<<x;
    }
    return 0;
}
