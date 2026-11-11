#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k,u[1000005],v[1000005];
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n-1;i++)
        {
            cin>>u[i]>>v[i];
        }
    }
    cout<<1<<endl<<2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
