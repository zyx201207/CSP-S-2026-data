#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdout);
    freopen("string.out","w",stdout);
    int a,b,c,n ,ans=0
    cin>>n;
    if(a==a&&b==b&&c==c)
    {
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(b>a)
        {
            change[a][b];
        }
        if(a>b)
        {
            change[b][a];
        }
        if(a>c)
        {
        change[a][c];
        }
        if(c>a)
        {
            change[c][a];
        }
        if(b>c)
        {
            change[b][c];
        }
        if(c>b)
        {
            change[c][b];
        }
        ans++;
    }
    cout<<ans
    return 0;
}
