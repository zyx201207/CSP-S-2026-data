#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[n-1];
    return 0;
}
