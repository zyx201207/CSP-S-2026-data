#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char c[maxn];
int a[maxn];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    long long sum=0,ans=0;
    int las=n,d=1;
    for(int i=1;i<=n;i++)
    {
        if(las<=i)break;
        if(a[las]-d+1>=a[i])
        {
            if(c[las]!=c[i])
            {
                ans+=a[i];
            }
            d+=a[i];
            if(d==a[las]+1)
            {
                las--;
                d=1;
            }
        }
        else
        {
            i--;
            a[i]-=(a[las]-d+1);
            las--;
            d=1;
        }
    }
    cout<<ans;
    return 0;
}
