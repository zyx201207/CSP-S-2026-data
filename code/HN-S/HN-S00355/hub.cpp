#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr first
#define sc second
#define pii pair<int,int>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define ro(i,r,l) for(int i=r;i>=l;i--)
const int N=1e6+5;
int Caseid,T,n,k,f[N],tmp[N],vis[N];
vector<int>e[N];
void dfs(int u,int fa){
    vis[u]=1;
    for (auto v:e[u]){
        if (!tmp[v]||vis[v])
            continue;
        dfs(v,u);
    }
}
queue<int>q;
namespace kis2{
    int mx,id,dep[N],tmp[N],f[N];
    vector<int>qr[N],de;
    void dfs1(int u,int fa){
        dep[u]=dep[fa]+1;
        if (dep[u]>mx)
            mx=dep[u],id=u;
        for (auto v:e[u]){
            if (tmp[v]||v==fa)
                continue;
            dfs1(v,u);
        }
    }
    bool dfs2(int u,int fa,int to){
        if (u==to){
            de.push_back(u);
            tmp[u]=1;
            return 1;
        }
        for (auto v:e[u]){
            if (v==fa)
                continue;
            if (dfs2(v,u,to)){
                tmp[u]=1;
                de.push_back(u);
            }
        }
        return tmp[u];
    }
    void solve(){
        while (T--){
            cin>>n>>k;
            fo(i,1,n)
                tmp[i]=0,e[i].clear();
            fo(i,1,n-1){
                int u,v;
                cin>>u>>v;
                e[u].push_back(v);
                e[v].push_back(u);
            }
            int id1,id2;
            mx=0,id=0,dfs1(1,0);
            id1=id,mx=0,id=0,dfs1(id1,0);
            id2=id;
            // cout<<id1<<' '<<id2<<'\n';
            de.clear();
            dfs2(id1,0,id2);
            fo(i,1,n)
                if (tmp[i]){
                    mx=id=0;
                    dfs1(i,0);
                    f[i]=mx-1;
                }
            int L=0,R=n,d=de.size();
            // fo(i,0,d-1)
            //     cout<<de[i]<<' '<<f[de[i]]<<'\n';
            while (L<R){
                int mid=(L+R)>>1,sb=0;
                fo(i,0,d-1)
                    qr[i].clear();
                fo(i,0,d-1){
                    if (f[i]>mid){
                        sb=1;
                        break;
                    }
                    int l=max(0ll,i-mid+f[de[i]]),r=min(d-1,i+mid-f[de[i]]);
                    qr[l].push_back(r);
                }
                if (sb){
                    L=mid+1;
                    continue;
                }
                int mn=1e18,c=0;
                fo(i,0,d-1){
                    if (i>mn)
                        c++,mn=1e18;
                    for (auto j:qr[i])
                        mn=min(mn,j);
                }
                if (mn<1e18)
                    c++;
                if (c>2)
                    L=mid+1;
                else R=mid;
            }
            cout<<R<<'\n';
        }
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>Caseid>>T;
    if (Caseid<=3){
        while (T--){
            cin>>n>>k;
            fo(i,1,n)
                e[i].clear();
            fo(i,1,n-1){
                int u,v;
                cin>>u>>v;
                e[u].push_back(v);
                e[v].push_back(u);
            }
            int rrs=1e18;
            fo(S,0,(1ll<<n)-1){
                int pc=0;
                fo(i,1,n){
                    tmp[i]=((S>>(i-1))&1);
                    pc+=(S>>(i-1))&1;
                    vis[i]=0;
                }
                if (pc!=k)
                    continue;
                int c=0;
                fo(i,1,n)
                    if (tmp[i]&&!vis[i])
                        dfs(i,0),c++;
                if (c>2)
                    continue;
                fo(i,1,n){
                    if (tmp[i])
                        q.push(i),f[i]=0;
                    else f[i]=1e18;
                }
                int rs=0;
                while (q.size()){
                    int u=q.front();
                    rs=max(rs,f[u]);
                    q.pop();
                    for (auto v:e[u])
                        if (f[v]>=1e18){
                            f[v]=f[u]+1;
                            q.push(v);
                        }
                }
                rrs=min(rs,rrs);
            }
            cout<<rrs<<'\n';
        }
        return 0;
    }
    if (Caseid==13||Caseid==14){
        while (T--){
            cin>>n>>k;
            fo(i,1,n-1){
                int u,v;
                cin>>u>>v;
            }
            int m=n/2;
            if (k<m){
                int c1=m/4,c3=m/4,c2=m-2-c1-c3;
                k-=2;
                while (k--){
                    int x1=c1,x2=(c2+1)/2,x3=c3;
                    if (x1>=x2&&x1>=x3)
                        c1--;
                    else if (x3>=x1&&x3>=x2)
                        c3--;
                    else c2--;
                }
                cout<<max(max(c1,c3),(c2+1)/2)+1<<'\n';
            }
            else if (k<n)
                cout<<"1\n";
            else cout<<"0\n";
        }
        return 0;
    }
    if (Caseid==7||Caseid==11||Caseid==12){
        kis2::solve();
        return 0;
    }
    return 0;
}