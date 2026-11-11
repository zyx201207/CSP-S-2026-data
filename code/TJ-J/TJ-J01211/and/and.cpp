#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int a[N],n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int x=a[n];
    for(int i=n-1;i>=n-m;i--)
    {
        x=(x&a[i]);
    }
    cout<<x;
    return 0;
}
