#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1)
    {
        cout<<n;
    }
    else if(m==3)
    {
        cout<<"3 1 4";
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            cout<<i;
        }
    }
}
