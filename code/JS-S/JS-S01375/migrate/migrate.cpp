#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{

    int f=1,x=0;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=getchar();
    return f*x;
}
const int MAXN=1e6+9;
int c,t,n,d,dism[MAXN],plans[MAXN],a[MAXN];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();t=read();
    while(t--)
    {
        for(int i=1;i<=n;i++)dism[i]=0x3f3f3f3f3f3f,plans[i]=0;
        n=read();d=read();
        int ans=0;
        for(int i=1;i<=n;i++)a[i]=read();
        for(int l=1;l<n;l++)
        {
        for(int i=1;i<=n;i++)dism[i]=0x3f3f3f3f3f3f,plans[i]=0;
        plans[l]=1;dism[l]=0;
        int dismmin=0,plan=1,lmin=l;
        for(int i=l;i<=n;i++)
        {
            for(int j=i-1;j>=l&&a[i]-a[j]<=d;j--)
            {
                if(dism[j]+1==dism[i])plans[i]+=plans[j];
                else if(dism[j]+1<dism[i])plans[i]=plans[j],dism[i]=dism[j]+1;
                //cout<<l<<" "<<i<<" "<<j<<" "<<plans[i]<<" "<<dism[i]<<endl;
            }
        }
        for(int i=l+1;i<=n;i++)ans+=(plans[i]==2);//,cout<<l<<" "<<i<<" "<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
