#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500005],max1 = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){cin >> a[i];max1 += a[i];}
    sort(a+1,a+n+1);
    for(int z = 2;z <= n;z++)
    {
        long long p = 1000005;
        for(int j = 2;j <= n-z+2;j++)
        {
            long long nm = 0;
            for(int i = j;i <= j+z-2;i++) nm += a[i]-a[i-1];
            p = min(p,nm);
        }
        if(p > m){
            cout << z-1;
            return 0;
        }
    }
    if((m+max1)%n == 0) cout << n;
    else cout << n-1;
    return 0;
}
