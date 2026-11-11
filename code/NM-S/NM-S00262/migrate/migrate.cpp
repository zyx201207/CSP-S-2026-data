#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
int a[100000005];
int cnt;

signed main()
{
    freopen ("migrate.in","r",stdin);
    freopen ("migrate.out","d",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
            if(a[j]-a[j-d]==d)
            {
                cnt++;
            }
        }
    }
    for(int i=1;i<=t;i++)
    {
        cout<<cnt<<endl;
    }

    return 0;
}
