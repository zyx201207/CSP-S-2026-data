#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m;
ll res,a[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(m==1)
    {
        cout<<a[n]<<endl;
        return 0;
    }
    else if(m==2)
    {
        res=-inf;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
                res=max(res,a[i]&a[j]);
        }
        cout<<res<<endl;
        return 0;
    }
    res=a[n];
    for(int i=n-1;i>=n+1-m;i--)
        res&=a[i];
    cout<<res<<endl;
    return 0;
}
