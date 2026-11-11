#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int i=1;i<=m;i++)
        {
           if(n<m)
           {
               cout<<1;
           }
           else
           {
               cout<<0;
           }
        }
    }
    return 0;
}
