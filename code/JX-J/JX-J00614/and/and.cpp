#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxa;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            maxa=max(maxa,a[i]&a[j]);
        }
    }
    cout<<maxa;
    return 0;
}
