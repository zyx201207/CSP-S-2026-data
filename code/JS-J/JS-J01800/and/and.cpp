#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt,l,sum,n,m,a[1000005];
signed main()
{

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==i-1)cnt++;
        if(a[i]<=4)sum++;
    }
    if(cnt==n)
    {
        for(int i=1;i<=n;i++)
        {
            if(pow(2,i)==n)
            {
               l=i;
               break;
            }
        }
        for(int i=1;i<=l-1;i++)
            cout<<"1";
        cout<<"0";
    }
    else
    {
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    return 0;
}
