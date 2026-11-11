#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans=0,a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m-1;i++)
    {
        int mx=-1,mj,ml;
        if(i==1){
        for(int j=1;j<=n;j++)
        {
            for(int l=1;l<=n;l++)
            {
                if((a[j]&a[l])>mx&&j!=l)
                {
                    mx=a[j]&a[l];
                    mj=j;
                    ml=l;
                }
            }
        }
        }
        else{
        for(int j=1;j<=n;j++)
        {
            if((ans&a[j])>mx)
            {
                    mx=a[j];
                    mj=j;
            }
        }
        }
        if(i==1)ans=mx;
        else ans&=mx;
        a[mj]=0,a[ml]=0;
    }
    cout<<ans;
    return 0;
}
