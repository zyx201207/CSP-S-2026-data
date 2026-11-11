#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k,u,v;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k;
        for(int j=1;j<=n-1;j++){
            cin>>u>>v;
        }
        if(n%5==0)
            cout<<n/5;
        else
            cout<<n/5+1;

    }


    return 0;
}
