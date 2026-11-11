#include<bits/stdc++.h>
using namespace std;
string s[10000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0,ans=0;
    cin >> n;
    for(long long i = 1;i <= n;i++)
    {
        long long x;
        cin >> x;
        ans+=x;
        string y;
        cin >> y;
        for(long long j = 1;j <= x;j++)
        {
            s[j]=y;
        }
    }
    long long x = 1;
    for(long long i = n;i >= ans/2-1;i--)
    {
        if(s[i]==s[x])
        {
            x++;
            continue;
        }
        else
        {
            x++;
            s[i] = s[x];
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
