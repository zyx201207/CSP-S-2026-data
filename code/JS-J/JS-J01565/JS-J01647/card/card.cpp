#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int hx[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n+1],b[n+1];
    ll ans[m+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=i;
        if(i<=m)ans[i]=0;
        hx[a[i]]++;;
    }
    for(int i=1;i<n;i++)
    {
        if(hx[a[i]]==1)
        {
            ans[a[i]]+=b[i];
            continue;
        }
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]==a[i])
            {
                break;
            }
            b[j]-=b[i];
        }
        hx[a[i]]--;
    }
    ans[a[n]]+=n;
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
