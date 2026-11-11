#include<bits/stdc++.h>
using namespace std;
int x[500005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    int zx=INT_MAX;
    for(int i=2;i<=n;i++)
    {
        zx=min(zx,abs(x[i]-x[i-1]));
    }
    if(zx>m)
    {
        cout<<0;
        return 0;
    }
    if(zx==m)
    {
        cout<<1;
        return 0;
    }
    cout<<int(sqrt(m*2));
    return 0;
}
