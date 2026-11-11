#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],x[300005]={1};
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        x[a[i]]++;
    }
    for(int i=1;i<=m;i++)
    {
        x[i]+=x[i-1]-1;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<i+x[i]-1<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
