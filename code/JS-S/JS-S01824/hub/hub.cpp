#include<bits/stdc++.h>
using namespace std;
int c,t,u[1000006]={},v[1000005]={};
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            cin>>u[i]>>v[i];
        }
        if(n==k) {
            cout<<0<<endl;
            continue;
        }
        if(k>=(n-1)/2){
            cout<<1<<endl;
            continue;
        }
        else cout<<2;
    }
    return 0;
}
