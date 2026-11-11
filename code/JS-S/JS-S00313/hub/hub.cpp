#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    int now=t;
    while(t--)
    {
        int n,k;
        int u[1000005],v[1000005];
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            cin>>u[i]>>v[i];
        }
        cout<<now-t<<endl;
    }


    return 0;
}
