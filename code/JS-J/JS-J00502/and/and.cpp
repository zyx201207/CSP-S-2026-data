#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[10005],b[10005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        while(a[i])
        {
            b[i]=a[i]%2;
            a[i]/=2;
        }
    }
}
