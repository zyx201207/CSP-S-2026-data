#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e6+10;
ll C,T,n,d,ans,island[M];
bool ismask[M];
bool check(int x,int y)
{
    ll minlen=M,sumlen=0;
    for(ll mask=0;mask<=(1<<n);mask++)
    {
        memset(ismask,0,sizeof(ismask));
        for(int i=0;i<n;i++)
        {
            if((mask>>i)&1)
            {
                ismask[i+1]=1;
            }
        }
        bool ishefa=1;
        if(ismask[x]==0||ismask[y]==0) ishefa=0;
        for(int i=1;i<x;i++)
        {
            if(ismask[i]==1) ishefa=0;
        }
        for(int i=y+1;i<=n;i++)
        {
            if(ismask[i]==1) ishefa=0;
        }
        ll len=0,lst=x;
        for(int i=x+1;i<=y;i++)
        {
            if(ismask[i]==1)
            {
                if((island[i]-island[lst])>d)
                {
                    ishefa=0;
                    break;
                }
                len++;
                lst=i;
            }
        }
        if(ishefa==0) continue;
        if(minlen==len) sumlen++;
        else if(len<minlen)
        {
            sumlen=1;
            minlen=len;
        }
    }
    if(sumlen==2) return 1;
    return 0;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>island[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(check(i,j)==1) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
