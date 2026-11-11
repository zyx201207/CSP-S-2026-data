#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]&a[j]>sum)sum=a[i]&a[j];
        }
    }
    cout<<sum;
}
