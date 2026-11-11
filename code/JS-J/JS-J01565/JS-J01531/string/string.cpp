#include <bits/stdc++.h>
using namespace std;
char a[10*10*10*10*10*2+10];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long x;
    char s;
    long long cnt=0;
    for (int i=1;i<=n;i++)
    {
        cin>>x>>s;
        for(long long j=cnt;j<cnt+x;j++)
        {
            a[cnt]=s;
            cnt++;
        }
    }
    long long ans=0;
    for (long long i=0;i<cnt/2;i++)
    {
        if (a[i]!=a[cnt-1-i])
        {
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
