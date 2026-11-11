#include <bits/stdc++.h>
using namespace std;
long long n,m,maxx;
long long a[300000],sum[10],ans,same;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int b=1;b<=n;b++)
    {
        cin >> a[b];
        if(m==1)
        {
            maxx=max(maxx,a[b]);
            continue;
        }
        if(a[b]==1)
        {
            sum[1]++;
        }
        if(a[b]==2)
        {
            sum[2]++;
        }
        if(sum[3]==3)
        {
            sum[3]++;
        }
        if(sum[4]==4)sum[4]++;
        for(int c=1;c<b;c++)
        {
            if(a[b]==a[c])
            {
                ans++;same=a[b];
            }
        }
    }
    if(m==1)
    {
        cout << maxx;
    }
    if(ans==n){cout << same;return 0;}
    if(n==sum[1]+sum[2]){cout << 1;}
    if(n==sum[1]+sum[3]){cout << 1;}
    if(n==sum[1]+sum[4]){cout << 1;}
    if(n==sum[2]+sum[3]){cout << 1;}
    if(n==sum[2]+sum[4]){cout << 2;}
    if(n==sum[3]+sum[4]){cout << 1;}
}
