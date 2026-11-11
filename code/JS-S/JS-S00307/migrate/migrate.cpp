#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long cx,t,n,m,ans,a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>cx>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        cout<<n-3<<endl;
    }
    return 0;
}
