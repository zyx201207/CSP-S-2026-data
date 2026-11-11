#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
int n,m,maxn,ans;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>maxn)maxn=a[i];
    }
    if(m==1)
    {
        cout<<maxn;
    }
    else if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            ans=(ans&a[i]);
        }
        cout<<ans;
    }
    return 0;
}
