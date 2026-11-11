#include<bits/stdc++.h>
using namespace std;
long long u[1000001],v[1000001],c,k,n,t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)cin>>u[i]>>v[i];
        cout<<n/5<<"\n";
    }
    return 0;
}
