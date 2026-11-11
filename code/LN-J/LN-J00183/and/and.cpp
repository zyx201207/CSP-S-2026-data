#include<bits/stdc++.h>
using namespace std;
int a[10000010],b[10000010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        for(int j=0;j<=i;j++)
            b[i]=max(a[j]&b[i],b[i]);


    }
    cout<<b[n-1];
    return 0;
}
