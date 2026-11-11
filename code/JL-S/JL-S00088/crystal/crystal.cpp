#include <bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long x=a[2]-a[1];
    long long s=m/x;
    long long i=1;
    int cnt=1;
    while(s>=i)
    {
        s-=i;
        i++;
        cnt++;
    }
    cout<<cnt;
}
