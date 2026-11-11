#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
#ifndef zzr
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
#endif 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    vector<int>pos(m+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    {
        bool sign=true;
        for(int i=2;i<=n;++i)sign&=(a[i]>=a[i-1]);
        if(sign)
        {
            for(int i=1;i<=n;++i)pos[a[i]]=i;
            for(int i=1;i<=m;++i)cout<<pos[i]<<' ';
            return 0;
        }
    }
    vector<int>b(n+1);
    vector<int>cnt(m+1);
    for(int i=1;i<=n;++i)
    {
        vector<int>pos(m+1,-1);
        int t=0;
        for(int j=i;j<=n;++j)
        {
            if(pos[a[j]]==-1)
            {
                b[++t]=a[j];
                pos[a[j]]=t;
            }
            else 
            {   
                int p=pos[a[j]];
                while(t>=p)
                {
                    pos[b[t]]=-1;
                    --t;
                }
                b[++t]=a[j];
                pos[a[j]]=t;
            }
        }
        vector<int>vis(m+1,0);
        for(int j=1;j<=t;++j)
        {
            if(!vis[b[j]])++cnt[b[j]];
            vis[b[j]]=1;
        }
    }
    for(int i=1;i<=m;++i)cout<<cnt[i]<<' ';
    cout<<'\n';
}
// 100+100+100+52
// happy boom zero!
// wo xiang shang mi huo xin wei da shang 
