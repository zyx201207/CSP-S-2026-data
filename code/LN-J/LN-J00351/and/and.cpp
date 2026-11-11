#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long cnt;
    cin>>n>>m;
    long long a[200009];
    for(int i=1;i<=n;i++)
    cin>>a[i];
    sort(a+1,a+n+1);
    cnt=a[n];
    for(int i=n;i>=n-m+1;i--)
    {
        cnt=cnt&a[i];
    }
    cout<<cnt;
    return 0;
}
