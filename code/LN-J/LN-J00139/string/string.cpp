#include <bits/stdc++.h>
using namespace std;
long long n,ans = 0;
long long num[20005];
char a[20005];
int main()
{
    freopen("string1.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long i = 1; i<=n; i++)
    {
        cin >> num[i];
        cin >> a[i];
    }
    for(long long j = 1; j<=n/2; j++)
    {
        if(a[j]!=a[n-j+1])
        {
            ans+=max(num[j],num[n-j+1]);
        }
        else
        {
            ans+=abs(num[j]-num[n-j+1]);
        }
    }
    cout << ans;
    return 0;
}
