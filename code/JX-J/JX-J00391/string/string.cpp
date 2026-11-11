#include <bits/stdc++.h>
using namespace std;
long long n,a[1000010],s[1000010],sum,ans;
char c[1000010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i]>>c[i], s[i] = s[i - 1] + a[i];
    sum = s[n];
    for(int i = 1;i <= n;i++)
    {
        long long l = s[i - 1] + 1;
        long long r = min(s[i],sum / 2);
        if(l > sum / 2) break;
        long long fl = sum - r + 1;
        long long fr = sum - l + 1;
        long long k1 = lower_bound(s + 1,s + n + 1,fl) - s;
        long long k2 = lower_bound(s + 1,s + n + 1,fr) - s;
//        cout<<l<<" "<<r<<" "<<fl<<" "<<fr<<" "<<k1<<" "<<k2<<endl;
        if(k1 == k2)
        {
            if(c[i] != c[k1]) ans += a[i];
            continue;
        }
        if(c[i] != c[k1]) ans += s[k1] - fl + 1;
        if(c[i] != c[k2]) ans += fr - s[k2 - 1];
        for(int j = k1 + 1;j < k2;j++)
            if(c[j] != c[i])
                ans += a[j];
        if(r == sum / 2) break;
    }
    cout<<ans<<endl;
    return 0;
}
