#include "bits/stdc++.h"
using namespace std;
int a[1000005];

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cout<<(n-m)/m<<endl;
    }
    return 0;
}
