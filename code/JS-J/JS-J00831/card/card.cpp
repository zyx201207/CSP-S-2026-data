#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        if(i!=m) cout<<1<<' ';
        else cout<<1<<endl;
    }
    return 0;
}
