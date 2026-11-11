#include<bits/stdc++.h>
using namespace std;
int a[2*100000+5],ans[2*100000+5];
int n,m,sum;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ans[++cnt]=a[i]&a[j];
        }
    }
    int maxn=-1;
    for(int i=1;i<=cnt;i++)
    {
        maxn=max(maxn,ans[i]);
    }
    cout<<maxn;
    return 0;
}
