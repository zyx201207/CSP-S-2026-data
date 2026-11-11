#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ans=1,nowa;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2; i<=n; i++)
    {
        int x=(a[i]-a[i-1])*(i-1);
        if(m>=x)
        {
            ans++;
            m-=x;
        }
        else
        {
            break;
        }
    }
    cout<<ans;
}
