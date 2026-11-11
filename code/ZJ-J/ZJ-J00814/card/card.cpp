#include<bits/stdc++.h>
using namespace std;
#define mid (l+r>>1)
int n,m,a[500005],cnt,b[500005],siz[500005],ans[300005];
struct node{int l,r,id;};
vector<int>v[300005],g[500005];
vector<node>vec;
int sc(node x)
{
    int ans=0,l=0,r=cnt;
    while(l<=r)
    {
        if(vec[mid].l>x.r)ans=mid,r=mid-1;
        else l=mid+1;
    }
    return ans;
}
void dfs(int x)
{
    siz[x]=1;
    for(int i:g[x])
    {
        dfs(i);
        b[vec[i].r]+=siz[i];
        b[vec[x].l]-=siz[i];
        // cout<<vec[i].r<<" "<<vec[x].l-1<<" "<<siz[i]<<"\n";
        siz[x]+=siz[i];
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],v[a[i]].push_back(i);
    for(int i=1;i<=m;i++)
    for(int j=0;j<v[i].size();j++)
        vec.push_back(node{v[i][j],v[i][v[i].size()-1],cnt++});
    vec.push_back({n+1,n+1,cnt});
    sort(vec.begin(),vec.end(),[](node x,node y){return x.l<y.l;});
    int j=0;
    for(node i:vec)if(i.id!=cnt)g[sc(i)].push_back(j++);//,cout<<sc(i)<<"->"<<j-1<<"\n";
    dfs(cnt);
    for(int i=1;i<=n;i++)b[i]+=b[i-1],ans[a[i]]+=b[i];
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
/*
luogu:1042346
终于AK J组了
T4好难啊（有青吗）
*/