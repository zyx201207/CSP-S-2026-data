#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto get_chain=[&](
        vector<vector<int>>& gra,
        int cant,int rt,
        vector<int>& chain,
        vector<int>& tmp,
        vector<int>& dp,
        vector<int>& dn,
        vector<int>& fa
    ) {
        int len=1;
        int u1=rt,u2=rt,lca=rt;

        auto dfs=[&](auto&& self,int u,int f) -> void {
            dp[u]=1;
            dn[u]=u;
            fa[u]=f;

            for(int v:gra[u]) {
                if(v==f||v==cant) continue;
                self(self,v,u);
                if(dp[u]+dp[v]>len) {
                    len=dp[u]+dp[v];
                    u1=dn[u];
                    u2=dn[v];
                    lca=u;
                }
                if(dp[v]>=dp[u]) {
                    dp[u]=dp[v]+1;
                    dn[u]=dn[v];
                }
            }
        };
        dfs(dfs,rt,0);

        while(u1!=lca) {
            chain.emplace_back(u1);
            u1=fa[u1];
        }
        chain.emplace_back(lca);
        tmp.clear();
        while(u2!=lca) {
            tmp.emplace_back(u2);
            u2=fa[u2];
        }
        for(int i=(int)tmp.size()-1;i>=0;--i)
            chain.emplace_back(tmp[i]);
    };

    int C,T;
    cin>>C>>T;
    while(T--) {

        int n,k;
        cin>>n>>k;
        vector<vector<int>> gra(n+1);
        for(int i=1;i<n;++i) {
            int u,v;
            cin>>u>>v;
            gra[u].emplace_back(v);
            gra[v].emplace_back(u);
        }

        vector<int> chain,tmp,fa(n+1),len_dp(n+1),dn(n+1);
        chain.reserve(n);
        tmp.reserve(n);
        get_chain(gra,0,1,chain,tmp,fa,len_dp,dn);

        vector<bool> on(n+1);
        for(int i:chain) on[i]=true;
        
        vector<int> len(n+1);
        vector<int> son(n+1);

        auto dfs_len=[&](auto&& self,int u,int f) -> void {
            len[u]=1;
            for(int v:gra[u]) {
                if(v==f||on[v]) continue;
                self(self,v,u);
                if(len[v]>=len[u]) {
                    len[u]=len[v]+1;
                    son[u]=v;
                }
            }
        };

        vector<int> dp(n+1);
        vector<int> st(n+1);
        int nxt=0;

        auto get_dp=[&](int rt) {
            dfs_len(dfs_len,rt,0);

            auto dfs=[&](auto&& self,int u,int f) -> void {
                if(!st[u]) {
                    st[u]=nxt+1;
                    nxt+=len[u];
                }
                dp[st[u]]=1;
                if(son[u]) {
                    st[son[u]]=st[u]+1;
                    self(self,son[u],u);
                }
                for(int v:gra[u]) {
                    if(v==f||on[v]) continue;
                    for(int i=0;i<len[v];++i)
                        dp[st[u]+i]+=dp[st[v]+i];
                }
            };
            dfs(dfs,rt,0);
            vector<int> res(len[rt]);
            for(int i=0;i<len[rt];++i)
                res[i]=dp[st[rt]+i];
            return res;
        };

        vector<vector<int>> dp1(chain.size());
        vector<vector<int>> dp2(chain.size());
        for(int i=0;i<chain.size();++i) {
            int u=chain[i];
            dp1[i]=get_dp(u);
            for(int v:gra[u]) {
                if(on[v]) continue;
                vector<int> chv;
                get_chain(gra,0,1,chv,tmp,fa,len_dp,dn);
                auto now=get_dp(chv[chv.size()>>1]);
                for(int i=1;i<now.size();++i)
                    now[i]+=now[i-1];
                if(!(chv.size()&1)) {
                    auto dpy=get_dp(chv[(chv.size()+1)>>1]);
                    for(int i=1;i<dpy.size();++i)
                        dpy[i]+=dpy[i-1];
                    if(dpy.size()<now.size()) swap(now,dpy);
                    for(int i=0;i<now.size();++i)
                        now[i]=min(now[i],dpy[i]);
                }
                if(dp2[i].empty()) dp2[i]=move(now);
                else {
                    if(now.size()<dp2[i].size()) swap(now,dp2[i]);
                    for(int x=0;x<dp2[x].size();++x)
                        dp2[i][x]=min(dp2[i][x],now[i]);
                }
            }
        }

        for(int i:chain) cerr<<i<<' ';
        cerr<<'\n';
        
        vector<int> need;
        need.reserve(chain.size());
        int l=0,r=(chain.size()-1)>>1,res=r;
        while(l<=r) {
            int mid=(l+r)>>1;
            need.clear();
            need.emplace_back(mid);
            if(mid!=chain.size()-mid-1)
                need.emplace_back(chain.size()-mid-1);
            int res1=chain.size()-mid-mid;
            int maxk=0;
            for(int i=mid+1;i<chain.size()-mid-1;++i) {
                if(dp1[i].size()>mid) {
                    need.emplace_back(i);
                    res1+=dp1[i][dp1[i].size()-mid-1];
                }
            }
            int maxd=0;
            for(int i=1;i<need.size();++i)
                maxd=max(maxd,need[i]-need[i-1]-1);
            res1-=maxd;
            cerr<<mid<<' '<<res1<<'\n';

            if(res1<=k) {
                res=mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        cout<<res<<'\n';
    }
}