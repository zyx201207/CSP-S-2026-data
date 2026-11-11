#include <bits/stdc++.h>
using namespace std;
char t[100000000];
#define int long long
int a;char b;
int now,ans;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int nowstart=1;
    for (int i=1;i<=n;i++)
    {
        cin>>a>>b;
        for (int j=0;j<a;j++)
        {
            t[nowstart+j]=b;
        }
        nowstart+=a;
    }
    int length=nowstart-1;
    int endth=length/2;
    for (int i=1;i<=endth;i++)
    {
        if (t[i]!=t[length+1-i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
