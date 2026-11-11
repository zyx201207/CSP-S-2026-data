#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002],mx,sm,t=1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    while(t<mx)
    {
        t<<=1;
    }
    while(t>>=1)
    {
        int ct=0;
        for(int i=1;i<=n;i++)
        {
            if((a[i]&sm+t)==sm+t)
            {
                ct++;
            }
        }
        if(ct>=m)
        {
            sm+=t;
        }
    }
    cout<<sm;
    return 0;
}
