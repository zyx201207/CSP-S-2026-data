#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,choosed[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        choosed[i]=true;
    }
    for(int i=29;i>=0;i--)
    {
        int res=0;
        for(int j=1;j<=n;j++)
        {
            if(choosed[j]&&(((a[j]>>i)&1)==1))
            res++;
        }
        if(res>=m)
        {
            ans+=(1<<i);
            for(int j=1;j<=n;j++)
            {
                if(!(choosed[j]&&(((a[j]>>i)&1)==1)))
                choosed[j]=false;
            }
        }
    }
    cout<<ans;
    return 0;
}
