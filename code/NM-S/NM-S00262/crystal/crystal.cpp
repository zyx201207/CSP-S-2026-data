#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int s;
int cnt;
int b;
int a[500005];
signed main()
{
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","d",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            s=(a[j]+a[j-1])/n+1;
            if(a[i]>=s)
            {
                b=a[j]-s;
            }
            if(a[i]<s)
            {
                b=s-a[j];
            }
        }
    }
    cout<<s<<endl;

    return 0;
}
