#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000010];
int b[1000010];
signed main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            for(int j=i;j<=m;j++)
            {
                sum=a[i]|a[j];
                b[i]=sum;
            }
        }
    }
    sort(b,b+n);
    cout<<b[n];
    return 0;
}
