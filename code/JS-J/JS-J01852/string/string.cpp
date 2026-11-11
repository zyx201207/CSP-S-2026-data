#include <bits/stdc++.h>
using namespace std;
int n,cnt;
int a[500005];
char st[10000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int t=1;
    char ch;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>ch;
        for(int j=1;j<=a[i];j++)
        {
            st[t]=ch;
            t++;
        }
    }
    for(int i=1;i<=t/2;i++)
    {
        if(st[i]!=st[t-i])cnt++;
    }
    cout<<cnt;
    return 0;
}
