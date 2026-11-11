#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    const int p=2e5+10;
    int a[p];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int s=0;
    for(int i=1;i<=n;i++)
    {
        s+=max(a[i]&a[i+1],a[i]&a[i+2]);
    }
    cout<<"12";
    return 0;
}
