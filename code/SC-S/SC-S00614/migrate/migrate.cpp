#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,T,n,d,x[2000005],nxt[2000005],lst[2000005],cntnxt[2000005],cntlst[2000005],rig[2000005],lef[2000005],ans;

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i],
            cntnxt[i]=cntlst[i]=lef[i]=rig[i]=0;
        int now=1;
        for(int i=1;i<=n;i++)
        {
            now=max(now,i);
            while(now<n&&x[now+1]-x[i]<=d)
                ++now;
            nxt[i]=now;
        }
        now=n;
        for(int i=n;i>=1;i--)
        {
            now=min(now,i);
            while(now>1&&x[i]-x[now-1]<=d)
                --now;
            lst[i]=now;
        }
        for(int i=1;i<=n;i++)
            cntnxt[nxt[i]]+=(nxt[i]!=i),
            cntlst[lst[i]]+=(lst[i]!=i);
        for(int i=1;i<=n;i++)
        {
            lef[i]+=cntnxt[i]+1;
            if(nxt[i]!=i&&lst[nxt[i]]==i)
                lef[nxt[i]]+=lef[i]-1;
        }
        for(int i=n;i>=1;i--)
        {
            rig[i]+=cntlst[i]+1;
            if(lst[i]!=i&&nxt[lst[i]]==i)
                rig[lst[i]]+=rig[i]-1;
        }
        ans=0;
        for(int i=1;i<n;i++)
            ans+=(((lef[lst[i]]-1)*(nxt[lst[i]]==i+1))+cntnxt[i+1]-(nxt[i]==i+1))*((rig[nxt[i+1]]-1)*(lst[nxt[i+1]]==i)+cntlst[i]-(lst[i+1]==i))*(lst[i]!=i)*(nxt[i+1]!=i+1);
        cout<<ans<<"\n";
    }
}