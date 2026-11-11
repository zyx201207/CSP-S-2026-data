#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int maxn[200005];
    int maxv=0;
    cin>>n>>m;
    int k=0;
     long long sum=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxv=max(maxv,a[i]);
    }

    if(m==1)
    {
        cout<<maxv;
        return 0;
    }
    long long ans=maxv;
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            ans=a[i]&ans;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=n,cishu=1;cishu<=m;i--,cishu++)
    {
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
