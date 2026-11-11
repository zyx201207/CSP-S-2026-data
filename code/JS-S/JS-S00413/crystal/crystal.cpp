#include<bits/stdc++.h>
using namespace std;
int n,m,i,sum=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int a[n];
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]<=0)
        {
            sum--;
        }
        if(a[i]/a[i-1]==2&&a[i]%a[i-1]==0)
        {
            continue;
        }
        else
        {
            sum++;
        }
    }
    cout<<sum+1;
    return 0;
}
