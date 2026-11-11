#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],ans;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;i++)
        {
            ans=max(ans,a[i]&a[j]);
        }
    }
    cout<<ans;
    return 0;
}
