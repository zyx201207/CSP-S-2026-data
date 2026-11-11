#include <bits/stdc++.h>
using namespace std;
int zt[500010];
int a[510][500010];
int ak[510];
map<int,bool>f[510];
map<int,bool>s[500010];
vector<int>ff[510];
vector<int>ss[500010];
bool fa[500010][510];
int minn;
int st,ed;
void dfs(int now,int tr,int ti)
{
    if(now==ed)
    {

        minn=min(minn,(ti+a[tr][now]));
        return;
    }
    fa[now][tr]=1;

    for(int i = 0;i < ff[tr].size();i++)
    {
        if(!fa[ff[tr][i]][tr])
        {
            fa[ff[tr][i]][tr]=1;
            dfs(ff[tr][i],tr,ti);
            fa[ff[tr][i]][tr]=0;
        }
    }
    for(int i = 0;i < ss[now].size();i++)
    {
        if(!fa[now][ss[now][i]])
        {
            fa[now][ss[now][i]]=1;
            dfs(now,ss[now][i],ti+a[tr][now]+a[ss[now][i]][now]);
            fa[now][ss[now][i]]=0;
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<= m;i++)
    {
        cin>>zt[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin>>ak[i];
        for(int j = 1;j <= ak[i];j++)
        {
            int x;
            cin>>x>>a[i][x];
            f[i][x]=1;
            s[x][i]=1;
            ff[i].push_back(x);
            ss[x].push_back(i);
        }
    }
    while(q--)
    {
        cin>>st>>ed;
        int ans=0;
        ans+=zt[st];
        ans+=zt[ed];
        for(int i = 0;i < ss[st].size();i++)
        {
            minn=2e9;
            dfs(st,ss[st][i],ans+a[ss[st][i]][st]);
        }
        cout << minn<<endl;
    }
    return 0;
}
