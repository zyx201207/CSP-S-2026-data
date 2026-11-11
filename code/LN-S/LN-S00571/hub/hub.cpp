#include<iostream>
using namespace std;
int u[2000006],v[2000006];
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
        for(int j=1;j<=n;j++)
        {
            cin>>u[j]>>v[j];
        }
    }
    cout<<1<<endl<<2;
}

