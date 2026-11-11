#include <bits/stdc++.h>
using namespace std;

//istream &fin=cin;
//ostream &fout=cout;
ifstream fin("migrate.in");
ofstream fout("migrate.out");
#ifdef LOCAL
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

using u8=unsigned char;
using u32=unsigned;
using i32=int;
using u64=unsigned long long;
using i64=long long;

#define FOR(i,a,b) for(u32 i=a;i<=(b);i++)
#define REP(i,a,b) for(u32 i=a;i<(b);i++)
#define RFOR(i,a,b) for(u32 i=(a)+1;i-->b;)

template<typename T,typename U=T>
bool ckmin(T&a,U&&b){
    return b<a&&(a=forward<U>(b),true);
}

constexpr u32 kN=1'000'005;
u32 c,t,n,k;
vector<u32> tree[kN];
u32 dis[kN],fa[kN],dia[kN],dia_len;

namespace solution1{
    constexpr u32 kN=4005;
    bool is_on[kN];
    u32 f[kN][kN],mdep[kN],tmp[kN],sz[kN],dep[kN];
    
    void dfs(u32 u,u32 father){
        fill_n(f[u],n+1,kN);
        mdep[u]=dis[u];
        for(u32 v:tree[u]){
            if(v!=father){
                dis[v]=dis[u]+1;
                dfs(v,u);
                mdep[u]=max(mdep[u],mdep[v]);
            }
        }
        f[u][1]=0;
        sz[u]=1;
        for(u32 v:tree[u]){
            if(v!=father){
                fill_n(tmp+1,sz[u]+sz[v],kN);
                FOR(i,1,sz[u]){
                    FOR(j,0,sz[v]){
                        ckmin(tmp[i+j],max(f[u][i],f[v][j]));
                    }
                }
                sz[u]+=sz[v];
                copy_n(tmp+1,sz[u],f[u]+1);
            }
        }
        f[u][0]=mdep[u]-dis[u]+1;
    }
    void dfs1(u32 u,u32 father){
        for(u32 v:tree[u]){
            if(v!=father&&!is_on[v]){
                dis[v]=dis[u]+1;
                dfs1(v,u);
            }
        }
        for(u32 v:tree[u]){
            if(v!=father&&!is_on[v]){
                dis[u]=max(dis[u],dis[v]);
            }
        }
    }
    void solve(){
        fill_n(is_on+1,n,false);
        FOR(i,1,dia_len){
            is_on[dia[i]]=true;
        }
        FOR(i,1,dia_len){
            dis[dia[i]]=0;
            dfs1(dia[i],0);
            dep[dia[i]]=dis[dia[i]];
        }
        dis[dia[dia_len/2]]=dis[dia[dia_len/2+1]]=0;
        dfs(dia[dia_len/2],dia[dia_len/2+1]);
        dfs(dia[dia_len/2+1],dia[dia_len/2]);
        i32 dis_l=0,dis_r=dia_len/2;
        u32 ans=kN;
        RFOR(l,dia_len/2,1){
            dis_l=-(dia_len/2+1);
            FOR(r,dia_len/2+1,dia_len){
                REP(j,1,k){
                   ans=min(ans,max({u32(dis_l+r),u32(dis_r-l),f[dia[l]][j],f[dia[r]][k-j]}));
                }
                dis_l=max(dis_l,i32(dep[dia[r]]-r));
                dis_r=max(dis_r,i32(dep[dia[r]]+r));
            }
            dis_r=max(dis_r,i32(dep[dia[l]]+l));
            dis_l=max(dis_l,i32(dep[dia[l]]-l));
        }
        fout<<ans<<"\n";
    }
}
void dfs(u32 u,u32 father){
    dis[u]=dis[father]+1;
    fa[u]=father;
    for(u32 v:tree[u]){
        if(v!=father){
            dfs(v,u);
        }
    }
}
void test_case(){
    fin>>n>>k;
    FOR(i,1,n){
        tree[i].clear();
    }
    REP(i,1,n){
        u32 u,v;
        fin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,0);
    u32 s=max_element(dis+1,dis+n+1)-dis;
    dfs(s,0);
    u32 t=max_element(dis+1,dis+n+1)-dis;
    dia_len=0;
    for(u32 i=t;i!=s;i=fa[i]){
        dia[++dia_len]=i;
    }
    dia[++dia_len]=s;
    if(n<=4000){
        solution1::solve();
        return;
    }
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    fin>>c>>t;
    while(t--){
        test_case();
    }
}
