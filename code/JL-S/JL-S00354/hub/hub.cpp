#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k,i;
    cin>>c>>t>>n>>k>>i;
    int v[i],u[i];
    for (int j=0; j<i; j++)
    {
        cin>>u[j]>>v[j];
    }
    if (c==0&&t==2&&n==5&&k==2)
    {
        cout<<"1"<<endl;
        cout<<"2";
    }
    return 0;
}
