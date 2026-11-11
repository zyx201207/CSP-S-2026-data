#include<bits/stdc++.h>
using namespace std;
int n,m,x[500010],hd=1,tl=1,st[500010],ans[500010];
bool f[500010];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>x[i];
    for(int _=1;_<=n;++_)
    {
        memset(st,0,sizeof(st));
        memset(f,0,sizeof(f));
        tl=1;
        for(int i=_;i<=n;++i)
            if(!f[x[i]])st[tl++]=x[i],f[x[i]]=true;
            else
                for(int j=hd;j<=tl;++j)
                    if(st[j]==x[i])
                    {
                        for(int k=j+1;k<=tl;++k)f[st[k]]=false;
                        tl=j+1;
                        break;
                    }
        for(int i=hd;i<=tl-1;++i)/*cerr<<st[i]<<' ',*/ans[st[i]]++;
        // cerr<<endl;
    }
    for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
}