#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,g;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int g=0;
        cin>>g;
    }
    for(int i=1;i<=m;i++)
    {
        if(i==g)
        {
            cout<<n<<" ";
        }
        else
        {
            cout<<n-m+i-1<<" ";
        }
    }
    return 0;
}
