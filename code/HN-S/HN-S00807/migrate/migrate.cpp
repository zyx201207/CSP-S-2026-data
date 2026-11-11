#include<bits/stdc++.h>
#define int long long

#define ls(p) tree[p].lt
#define rs(p) tree[p].rt
#define lowbit(x) x&(-x);
using namespace std;
const int maxn=2e6+5;
struct Node{
    int to,w;
};
struct node{
    int val,lt,rt;
}tree[maxn*30];
vector<Node>vt[maxn];
int n,dp[maxn],siz[maxn],x[maxn],d,to[maxn],tree1[maxn*4],tag[maxn*4],tov[maxn],root[maxn],cnt=0,mini=1e9,bai[maxn],remaxpos=0,maxipos=0,maxposval=0;
int newnode()
{
    cnt++;
    tree[cnt]={0,0,0};
    return cnt;
}
void updata1(int p,int p1,int l,int r,int x)
{
    if(l==r)
    {
        tree[p1].val=tree[p].val+1;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)
    {
        rs(p1)=rs(p);
        ls(p1)=newnode();
        updata1(ls(p),ls(p1),l,mid,x);
    }else
    {
        ls(p1)=ls(p);
        rs(p1)=newnode();
        updata1(rs(p),rs(p1),mid+1,r,x);
    }
    tree[p1].val=tree[ls(p1)].val+tree[rs(p1)].val;
}
int query3(int p,int p1,int l,int r)
{
    if(l==r)
    {
        maxposval=tree[p1].val-tree[p].val;
        return l;
    }
    int mid=(l+r)>>1;
    if(tree[rs(p1)].val-tree[rs(p)].val)
    {
        return query3(rs(p),rs(p1),mid+1,r);
    }else
        return query3(ls(p),ls(p1),l,mid);
}
void query2(int p,int p1,int pl,int pr,int l,int r)
{
    if(tree[p1].val!=tree[p].val==0)
        return;
    if(l>r)
        return;
    if(l<=pl&&r>=pr)
    {
        if(!remaxpos&&tree[p1].val!=tree[p].val)
        {
            remaxpos=query3(p,p1,pl,pr);
            // cerr<<pl<<" "<<pr<<" "<<remaxpos<<"\n";
        }
        return ;
    }
    int mid=(pl+pr)>>1,ans=0;
  
    if(r>mid)
        query2(rs(p),rs(p1),mid+1,pr,l,r);  
    if(remaxpos)
        return;
    if(l<=mid)
        query2(ls(p),ls(p1),pl,mid,l,r);
}
int query(int p,int p1,int pl,int pr,int l,int r)
{
    if(l>r)
        return 0;
    if(l<=pl&&r>=pr)
    {
        if(!maxipos&&tree[p1].val!=tree[p].val)
        {
            maxipos=query3(p,p1,pl,pr);
            query2(p,p1,pl,pr,pl,maxipos-1);
        }
        else
        if(!remaxpos&&tree[p1].val!=tree[p].val)
        {
            remaxpos=query3(p,p1,pl,pr);
        }
        // cerr<<" "<<pl<<" "<<pr<<" "<<
        return tree[p1].val-tree[p].val;
    }
    int mid=(pl+pr)>>1,ans=0;
    if(r>mid)
        ans+=query(rs(p),rs(p1),mid+1,pr,l,r);
    if(l<=mid)
        ans+=query(ls(p),ls(p1),pl,mid,l,r);
    return ans;
}
void updata(int p,int pl,int pr,int l,int r,int d)
{
    if(l<=pl&&r>=pr)
    {
        tree1[p]+=d;
        return;
    }
    int mid=(pl+pr)>>1;
    if(l<=mid)
        updata(p<<1,pl,mid,l,r,d);
    if(r>mid)
        updata(p<<1|1,mid+1,pr,l,r,d);
}
int query(int p,int l,int r,int x)
{
    if(l==r)
        return tree1[p];
    int mid=(l+r)>>1,ans=tree1[p];
    if(x<=mid)
        ans+=query(p<<1,l,mid,x);
    else
        ans+=query(p<<1|1,mid+1,r,x);
    return ans;
}
void dfs(int x)
{
    siz[x]=1;
    bai[x]=1;
    for(int i=0;i<vt[x].size();i++)
    {
        dfs(vt[x][i].to);
        siz[x]+=siz[vt[x][i].to];
        // vt[x][i].w=dp[vt[x][i].to];
        bai[x]++;
        for(int j=0;j<vt[vt[x][i].to].size();j++)
        {
            if(vt[vt[x][i].to][j].to+1==vt[x][i].to)
            {  
                dp[x]+=vt[vt[x][i].to][j].w;
                vt[x][i].w+=vt[vt[x][i].to][j].w;
                bai[x]+=bai[vt[vt[x][i].to][j].to];
            }else
            {
                int t=query(root[vt[vt[x][i].to][j].to],root[vt[x][i].to-1],1,n,x,x);
                //  if(x==8&&vt[vt[x][i].to][j].to==3)
                //     {
                //         cerr<<j<<" "<<vt[vt[x][i].to][j].w<< " "<<t<<" 114514\n";
                //     }
                if(t==0)
                {
                   
                    dp[x]+=vt[vt[x][i].to][j].w;
                  
                    vt[x][i].w+=vt[vt[x][i].to][j].w;
                    bai[x]+=bai[vt[vt[x][i].to][j].to];
                }else
                {
                if(t==1)
                {
                    dp[x]+=bai[vt[vt[x][i].to][j].to];
                    vt[x][i].w+=bai[vt[vt[x][i].to][j].to];
                }
                }
            }
            // if(vt[x][i].to==7)
            // {
            //     cerr<<vt[x][i].w<<"\n";
            // }
            // cerr<<vt[x][i].to<<" "<<vt[x][i].w<<"\n";
        }
        // if(x==8)
        // {
        //     cerr<<dp[x]<<"\n";
        // }
    }
    // cerr<<x<<" "<<dp[x]<<" "<<bai[x]<<"\n";
}
void solve()
{
    cnt=0;
    tree[0]={0,0,0};
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(int i=1;i<=n;i++)
    {
        int lt=i-1,rt=n+1;
        while(lt+1!=rt)
        {
            int mid=(lt+rt)>>1;
            if(x[mid]-x[i]<=d)
                lt=mid;
            else
                rt=mid;
        }
        to[i]=lt;
        if(lt!=i)
        {
            vt[lt].push_back({i,0});
        }
        root[i]=newnode();
        updata1(root[i-1],root[i],1,n,to[i]);
        // cerr<<i<<" "<<to[i]<<"\n";
    }
    for(int i=1;i<=n;i++)
        if(to[i]==i)
            dfs(i);
    int ans=0;
    // cerr<<"\n";
    for(int i=1;i<=n;i++)
    {
        ans+=query(1,1,n,i);
        updata(1,1,n,i+1,to[i],dp[i]);
        for(auto v:vt[i])
        {
            if(v.to+1!=i)
            {
                maxipos=remaxpos=maxposval=0;
                int t=query(root[v.to],root[i-1],1,n,i+1,n);
                // cerr<<i<<" "<<v.to<<" "<<maxipos<<" "<<remaxpos<<" "<<maxposval<<" "<<v.w<<"\n";
                if(t>=1&&maxposval==1)
                {
                    if(remaxpos)
                    updata(1,1,n,remaxpos+1,maxipos,bai[v.to]-v.w);
                    else
                    updata(1,1,n,i+1,maxipos,bai[v.to]-v.w);
                    if(remaxpos)
                    updata(1,1,n,i+1,remaxpos,-v.w);
                }else
                {
                    if(maxipos)
                    updata(1,1,n,i+1,maxipos,-v.w);
                }
            }
        }
        // cerr<<i<<" "<<ans<<"\n";
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++)
    {
        vt[i].clear();
        dp[i]=0;
        to[i]=0;
        siz[i]=0;
        tree1[i]=0;
        tov[i]=0;
        x[i]=0;
        bai[i]=0;
    }
    for(int i=1;i<=4*n;i++)
        tree1[i]=0;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        solve();
    }
}