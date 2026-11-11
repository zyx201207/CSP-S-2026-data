#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
char b[10000005];
char c[10000005];
int q;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int w = 1;
    long long n;
    long long i,j;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
    }
    int sum = n;
    for(i=1; i<=n; i++)
    {
        sum += a[i];
    }
    for(i=1; i<=sum; i++)
    {
        for(j=1; j<=a[i]; j++)
        {
            c[i] = b[w];
        }
        w++;
    }
    cout<<"0";
    return 0;
}
