#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,ma=-0x7f7f7f7f;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        max(a[i],ma);
    }
    cout<<ma;
    return 0;
}
