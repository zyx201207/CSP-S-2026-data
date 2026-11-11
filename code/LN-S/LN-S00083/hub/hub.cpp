#include <bits/stdc++.h>
using namespace std;
long long c,t;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    int x=1;
    while(t--)
    {
        long long n,k,u[20005],v[20005];
        for(int i=1;i<n;i++)
        {
            cin>>u[i]>>v[i];
        }
        cout<<x<<endl;
        x++;
    }
    return 0;
}
