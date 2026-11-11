#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int,int> mp;
int n;
ll m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    vector<int> a(n+1);
    ll d=0;
    bool t=true;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a.begin()+1,a.end());
    d=a[2]-a[1];
    for(int i=3;i<=n;i++)
        if(a[i]-a[i-1]!=d)
        {
            t=false;
            break;
        }
    if(t)
    {
        double ans=sqrt(((8ll*m+d)*1.0)/((4ll*d)*1.0))+0.5;
        cout<<int(ans)<<endl;
    }
    else
    {
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            ll k=0,ans=1;
            for(int j=i-1;j>=1;j--)
            {
                k+=abs(a[i]-a[j]);
                if(k>m) break;
                ans++;
            }
            res=max(res,ans);
        }
        cout<<res<<endl;
    }
    return 0;
}
