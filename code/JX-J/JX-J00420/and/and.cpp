#include <bits/stdc++.h>
using namespace std;
int n,m,a[200002];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int max_=-1;
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=max_) max_=a[i];
        }
    }
    if(m==n)
    {
        max_=1;
        for(int i=1;i<=n;i++)
        {
            max_=a[i]&max_;
        }
    }
    cout<<max_;
    return 0;
}
