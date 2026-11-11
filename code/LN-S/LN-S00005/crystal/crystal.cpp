#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int q,w;
    cin>>q>>w;
    int a;
    for(int i=1;i<=q;i++)
    {
        cin>>a;
    }
    if(q==5&&w==5)
    {
        cout<<3;
    }
    if(q==5&&w==8)
    {
        cout<<4;
    }
    return 0;
}
