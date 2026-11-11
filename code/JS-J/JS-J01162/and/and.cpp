#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,n,m;
ll a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    ll maxx = 0;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        maxx = max(maxx,a[i]);
    }
    if(m==1)
    {
        cout<<maxx<<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(m==n)
    {
        ll cnt = 1;
        for(int i = 1;i<=n;i++)
        {
            cnt = cnt&a[i];
        }
        cout<<cnt<<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(m==n-1)
    {
        ll ma = 0;
        for(int i = 1;i<=n;i++)
        {
            ll cnt = 1;
            for(int j = 1;j<=n;j++)
            {
                if(j==i)
                    continue;
                cnt = cnt&a[j];
            }
            ma = max(cnt,ma);
        }
        cout<<ma<<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    ll ma = 0;
    for(int i = 1;i<n;i++)
    {
        ll cnt = 0;
        for(int j = i+1;j<=n;j++)
        {
            cnt = a[i]&a[j];
        }
        ma = max(cnt,ma);
    }
    cout<<ma;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
