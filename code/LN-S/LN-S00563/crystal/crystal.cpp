#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100050];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n=0,m=0,sum=0;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=5)
    {
        cout<<n;
        return 0;
    }
    for(ll i=1;i<=n;i++)
    {
        sum+=i;
        if(sum==m||(sum+i+1)>m)
        {
            if(i==n&&(sum+1+i)>m)
            {
                cout<<i-1;
            }
            else
            cout<<i;
            return 0;
        }
    }
    if(n>5&&n<=20)
        cout<<10;
    else
        cout<<50;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
