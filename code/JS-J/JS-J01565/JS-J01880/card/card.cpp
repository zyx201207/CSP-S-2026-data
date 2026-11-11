#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<n<<' '<<m<<' '<<m;
    return 0;
}
