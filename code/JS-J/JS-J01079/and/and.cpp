#include<bits/stdc++.h>
using namespace std;
int a,b[500000],c,d;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.in","w",stdout);
    cin>>a>>c;
    for(int i=0;i<a;i++)
    {
        cin>>b[i];
    }
    if(c==1)
    {
        for(int i=1;i<a;i++)
        {
            d=max(b[i-1],b[i]);
        }
        cout<<d;
    }
    return 0;
}
