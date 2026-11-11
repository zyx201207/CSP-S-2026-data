#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=99999999;
int a[1000000];
int main()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    cout<<maxx;
    return 0;
}
