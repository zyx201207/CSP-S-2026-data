#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m; cin>>n>>m; int a[n+5];
    for(int i=0;i<n;i++) cin>>a[i];
    if(m==1)
    {
        int maxn=INT_MIN;
        for(int i=0;i<n;i++)
            if(a[i]>maxn) maxn=a[i];
        cout<<maxn; return 0;
    }
    else if(m==n)
    {
        int ans=a[0];
        for(int i=1;i<n;i++)
            ans=ans & a[i];
        cout<<ans; return 0;
    }
    else if(m==2)
    {
        int maxcnt=0;
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(a[i]&a[j]>maxcnt)
                    maxcnt=a[i]&a[j];
        cout<<maxcnt; return 0;
    }
    else if(m==3)
    {
        int maxcnt=0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                    if(a[i]&a[j]&a[k]>maxcnt)
                        maxcnt=a[i]&a[j]&a[k];
            }
        }
        cout<<maxcnt; return 0;
    }
    cout<<0;
    return 0;
}
