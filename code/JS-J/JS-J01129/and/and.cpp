#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=200010;
int n,m;
int a[N];
int tot,nxt[N];
ll ans=0;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    tot=n;
    for(int i=30;i>=0;i--)
    {
        int nxt_tot=0;
        int cnt=0;
        for(int j=1;j<=tot;j++)
        {
            cnt+=((a[j]>>i)&1);
        }
        if(cnt>=m)
        {
            ans|=(1ll<<i);
        }
        for(int j=1;j<=tot;j++)
        {
            if((ans>>i)&1)
                if(!((a[j]>>i)&1))
                    continue;
            nxt[++nxt_tot]=a[j];
        }
        tot=nxt_tot;
        for(int j=1;j<=tot;j++)
            a[j]=nxt[j];
    }
    printf("%lld",ans);
    return 0;
}
