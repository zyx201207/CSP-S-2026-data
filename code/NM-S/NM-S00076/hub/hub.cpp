#include<bits/stdc++.h>
using namespace std;
int main()
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while (t--){
        int f[1000005],u[1000006],n,m;
        cin>>n>>m;
        for (int i=1;i<=f;i++)
            cin>>f[i]>>u[i];
        if (f[i]>=1000005&&u[i]>=1000005)
            cout<<time(0)<<endl;
        else
            cout<<u[i]*1.0/v[i]+0.5<<endl;
    }
    return 0;
}
