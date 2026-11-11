#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
    return a > b;
}
long long a[200100];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n,cmp);
    long long sum = a[1];
    for(int i = 2;i<=m;i++)
    {
        sum = sum & a[i];
    }
    cout << sum;
    return 0;
}
