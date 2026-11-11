#include <iostream>
using namespace std;
int mian()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ci,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(ci[0]!=ci[5])
        {
            ans++;
        }
        if(ci[1]!=ci[4])
        {
            ans++;
        }
        if(ci[2]!=ci[3])
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
