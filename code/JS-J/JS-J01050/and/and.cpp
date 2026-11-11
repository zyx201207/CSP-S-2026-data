#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100006];
bool f[100006];
long long ks(long long k,long long sum)
{
    long long b;
    bool x=1;
    if(k==0) return sum;
    for(int i=1;i<n;i++)
    {
        if(!f[i])
        {
            if(x)
            {
                b = ks(k-1,sum&a[i]);
            }
            f[i] = 1;
            b = max(b,ks(k-1,sum&a[i]));
            f[i] = 0;
        }
    }
    return b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long m;
    cin >> n >> m;
    for(long long i=0;i<n;i++) cin >> a[i];
    cout << ks(m,4294967296);
    cout << '\n';
    return 0;
}
