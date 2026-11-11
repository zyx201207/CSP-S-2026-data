#include<bits/stdc++.h>
using namespace std;
long long a[300000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);

    cout<<a[n-m+1];
    return 0;
}





