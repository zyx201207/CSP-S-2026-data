#include <bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,mm,shu=0,mii=100005,maa=-100005;
    cin>>n>>mm;
    if(n<=16)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mii=min(mii,a[i]);
            maa=max(maa,a[i]);
        }
        for(int i=mii;i<=maa;i++)
        {
            int cnt=0,b[500010],m=mm;
            memset(b,0,sizeof(b));
            for(int j=1;j<=n;j++)
            {
                if(a[j]<=i)
                {
                    b[++cnt]=abs(a[j]-i);
                }
            }
            sort(b+1,b+cnt+1);
            bool f=true;
            int ans=0;
            for(int j=1;j<=cnt&&f;j++)
            {
                if(m>=b[j])
                {
                    ans++;
                    m-=b[j];
                }
                else f=false;
            }
            shu=max(shu,ans);
        }
        cout<<shu;
    }
    else
    {
        cout<<n;
    }
}
