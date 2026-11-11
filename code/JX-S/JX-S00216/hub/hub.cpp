#include<bits/stdc++.h>
using namespace std;
int v[20005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
        }
    }
    cout<<v[1]*v[2]*t/2;
    return 0;
}
