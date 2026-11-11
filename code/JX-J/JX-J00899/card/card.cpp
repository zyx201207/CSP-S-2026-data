#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=1;k<=j;k++)
            {
                if(a[k]==a[j])
                    break;
            }
        }
    }
    for(int i=1;i<=m;i++)
        cout<<n/m<<" ";
    return 0;
}
