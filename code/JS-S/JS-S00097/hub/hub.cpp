#include "bits/stdc++.h"
using namespace std;
int a[1000005];

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cout<<(n+m)/m<<endl;
    }
    return 0;
}
