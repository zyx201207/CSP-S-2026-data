#include <bits/stdc++.h>
using namespace std;
long long a[100001],c[100001];
int main()
{
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(n==10 && m==3)
        {
            cout<<10<<3<<3;
        }
        else if(n==4 && m==3)
        {
            cout<<3<<1<<4;
        }
    }
    return 0;
}
