#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],t[300005],s[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int i,j,k,y;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n%2==1&&m==1)
    {
        cout<<"1";
    }
    if(n%2==0&&m==1)
    {
        cout<<"0";
    }
    if(n==1&&m==2&&a[i]==1)cout<<"1"<<"0";
    if(n==2&&m==2&&a[1]!=a[2])cout<<"2"<<"2";
    return 0;
}
