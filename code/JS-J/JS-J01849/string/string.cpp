#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
long long l=0;
long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        char y;
        cin >> x >> y;
        for(long long j=l+1;j<=l+x;j++)
        {
            s[j]=y;
        }
        l+=x;
    }
    int m=l/2;
    for(long long i=m;i>=1;i--)
    {
        if(s[m]!=s[l+1-m])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
