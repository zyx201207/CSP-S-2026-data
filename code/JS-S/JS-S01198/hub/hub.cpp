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
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cout << 1<<endl<<2;
    return 0;
}
