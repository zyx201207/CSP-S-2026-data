#include <bits/stdc++.h>
using namespace std;
long long n,m;
string a[100005],q[100005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    while(m>0)
    {
        string p+=(m[i]-'0')%2;
        m%=2;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        while(a[i]>0)
        {
            q[i]+=(a[i]-'0')%2;
            a[i]/=2;
        }
    }
    int maxn=-1;
    for{int i=1;i<=n;i++}
    {
        int s=p^q[i];
        maxn=max(maxn,s);
    }
    return 0;
}
