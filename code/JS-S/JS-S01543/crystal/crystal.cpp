#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500001];
ll c[500001];
int f(int k)
{
    int cnt=1;
    int t=m;
    for(int i=k-1;i>=1;i--)
    {
        if(t>=a[k]-a[i])
        {
            cnt++;
            t -= (a[k]-a[i]);
        }
        else
        {
            break;
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=5000)
    {
        int maxc=-1;
        for(int i=1;i<=n;i++)
        {
            int tc=f(i);
            if(tc>maxc)
            {
            //    cout<<i<<" ";
                maxc = tc;
            }
        }
        cout<<maxc<<'\n';
    }
    else
    {
        int cnt=f(n);
        cout<<cnt;
    }
    return 0;
}
/*

*/
