#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],L=0;
char c[200005];
string s;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
            s+=c[i];
        L+=a[i];
    }
    if(n==1)
    {
        cout<<0;
    }
    if(n==2)
    {
        if(c[1]==c[2])
            cout<<0;
        else
        {
            int z=0;
            for(int i=0;i<=L/2-1;i++)
            {
                if(s[i]!=s[L-i-1])
                    z++;
            }
            cout<<z;

        }
    }
    else
    {
         int z=0;
            for(int i=0;i<=L/2-1;i++)
            {
                if(s[i]!=s[L-i-1])
                    z++;
            }
            cout<<z;
    }
    return 0;
}
