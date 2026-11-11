#include <iostream>
using namespace std;
int mian()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,ans;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(n>n-1)
        {
            n+=1;
            ans++;
        }
        if(n==n-1)
        {
            ans=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
