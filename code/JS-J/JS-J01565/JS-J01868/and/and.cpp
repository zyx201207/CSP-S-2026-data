#include<bits/stdc++.h>
using namespace std;
int a[200011],l[200011];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m,n,sum,s=32768*16384,ans=0;
    cin>>n>>m;
    sum=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(s!=0)
    {
        int x=1;
        for(int i=1;i<=sum;i++)
        {
            if((a[i]/s)%2==1)
            {
                l[x]=a[i];
                x++;
            }
        }
        if(x>m)
        {
            for(int i=1;i<=n;i++)
            {
                a[i]=l[i];
            }
            ans+=s;
            sum=x;
        }
        s/=2;
    }
    if(ans!=0)
    {
        cout<<ans;
    }
    else cout<<0;
    return 0;
}
