#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000000]={},v[1000000]={};
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int j=1;j<=t;j++)
    {
        cin>>n>>k;
        for(int i=1;i<=n-1;i++)
        {
            cin>>u[i]>>v[i];
        }
    }
    return 0;
}
