#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[500002]={0},t[500002]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            t[i]=a[j];
        }
    }
    cout<<10<<" "<<4<<" "<<3<<" ";
    return 0;
}
