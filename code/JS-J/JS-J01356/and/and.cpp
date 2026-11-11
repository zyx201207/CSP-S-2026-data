#include <bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
int main()
{
    freopen("and.in","w",stdin);
    freopen("and.out","r",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        while(a[i]!=0)
        {
            b[i]=a[i]%2;
            a[i]/=2;
        }
    }
    return 0;
}
