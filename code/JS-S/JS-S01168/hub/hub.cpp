#include<bits/stdc++.h>
#define pr pair
#define f first
#define s second
#define mp make_pair
#define ll long long
#define pii pr<int,int>
using namespace std;
vector<int> e[1000006];
int ta[1000006],tb[1000006];
int dt[1000006],st[1000006];
int cd[1000006];
bool vd[1000006];
int pf[1000006];
vector<int> ls[1000006];
int t;
bool h(int x,int y)
{
    return ta[x]==y||tb[x]==y;
}
void dfs(int x,int y)
{
    ls[t].push_back(x);
    if(!h(x,y)) return;
    vd[x]=1;
    dfs(ta[x]+tb[x]-y,x);
}
int px[1000006],sx[1000006];
int ch(int x,int s)
{
    vector<int>&w=ls[x];
    int cn=w.size()-1;
    int l=cn,r=0;
    for(int i=0;i<=cn;i++) if(dt[w[i]]>s) l=min(l,i),r=i;
    if(l+1>=r) return 0;
    px[l]=s;
    for(int i=l+1;i<r;i++)
    {
        px[i]=max(px[i-1]-1,min(s,st[w[i]]));
    }
    sx[r]=s;
    for(int i=r-1;i>l;i--)
    {
        sx[i]=max(sx[i+1]-1,min(s,st[w[i]]));
    }
    int rt=0;
    for(int i=l;i<r;i++) rt=max(rt,s*2-px[i]-sx[i+1]);
    return rt;
}
void sl()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++) ls[i].clear(),e[i].clear(),vd[i]=0,cd[i]=0,pf[i]=0,ta[i]=-1,tb[i]=-1;
    t=0;
    queue<int> cl,nl;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        u--;
        v--;
        cd[u]++;
        cd[v]++;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=0;i<n;i++) if(cd[i]==1) cl.push(i);
    for(int i=0;i<n;i++) if(cd[i]==2) ta[i]=e[i][0],tb[i]=e[i][1],st[i]=0;
    int l=-1,m,r=0;
    for(int i=1;i<n;i++)
    {
        while(cl.size())
        {
            int f=cl.front();
            cl.pop();
            dt[f]=i;
            pf[i]++;
            r=max(r,i-1);
            vd[f]=1;
            for(int j:e[f]) if(!vd[j])
            {
                cd[j]--;
                if(cd[j]==1) nl.push(j);
                if(cd[j]==2)
                {
                    st[j]=i;
                    for(int k:e[j]) if(!vd[k])
                    {
                        if(ta[j]==-1) ta[j]=k;
                        else tb[j]=k;
                    }
                }
            }
        }
        pf[i]+=pf[i-1];
        cl.swap(nl);
    }
    for(int i=0;i<n;i++) vd[i]=0;
    for(int i=0;i<n;i++) if(ta[i]!=-1&&!vd[i])
    {
        if(h(ta[i],i)) swap(ta[i],tb[i]);
        if(!h(ta[i],i))
        {
            ls[t].push_back(ta[i]);
            dfs(i,ta[i]);
            t++;
        }
    }
    while(l<r-1)
    {
        m=l+r>>1;
        int g=n-pf[m];
        if(g<=k) r=m;
        else
        {
            bool ok=0;
            for(int i=0;i<t;i++) if(ls[i].size()-2>=g-k)
            {
                ok|=ch(i,m)>=g-k;
            }
            if(ok) r=m;
            else l=m;
        }
    }
    cout<<r<<endl;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cid,z;
    cin>>cid>>z;
    while(z--) sl();
    return 0;
}
