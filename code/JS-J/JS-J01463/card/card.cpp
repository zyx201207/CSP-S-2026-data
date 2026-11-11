#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>a[i];
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    else cout<<n/2<<" "<<n-n/2;
    return 0;
}
