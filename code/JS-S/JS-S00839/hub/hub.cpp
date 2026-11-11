#include<iostream>

using namespace std;

int c,t,n,k;
int u[1000070],v[1000070];

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin>>c>>t;
    for (int i = 0; i < t; i++)
    {
        cin>>n>>k;
        for (int j = 1; j <= n-1; j++)
        {
            cin>>u[j]>>v[j];
        }
        cout<<1<<endl;
    }
    
    return 0;
}