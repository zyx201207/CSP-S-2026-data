#include<bits/stdc++.h>
#define rep(i,a,b) for(auto i=a;i<b;++i)
using namespace std;
ifstream inf("hub.in");
ofstream ouf("hub.out");
using lint=long long;
class tree{
private:
    vector<vector<int>> gr;
    auto dfs(int u,int f=-1)->pair<int,int>{
        auto res=make_pair(0,u);
        for(auto&i:gr[u]) if(i!=f){
            const auto[d,id]=dfs(i,u);
            res=max(res,make_pair(d+1,id));
        }
        return res;
    }
public:
    auto link(int u,int v){
        gr[u].emplace_back(v);
        gr[v].emplace_back(u);
    }
    auto d(){
        auto x=dfs(0).second,y=dfs(x).second;
        vector<int> uf(gr.size());
        auto get=[&](auto __self,int u,int f=-1)->void {
            uf[u]=f;
            for(auto&i:gr[u]) if(i!=f) __self(__self,i,u);
        };
        get(get,x);
        vector<int> res;
        while(y!=x) res.emplace_back(y),y=uf[y];
        res.emplace_back(x);
        return res;
    }
    tree(int _n):gr(_n){}
};
class chk_tree{
private:
    vector<vector<int>> gr;
    vector<int> len,cnt;
    vector<int> sub,dep,cst,uf;
    int req;
    auto init(int u,int f=-1)->void{
        len[u]=0;uf[u]=f;
        auto mx=0,smx=0;
        for(auto&i:gr[u]) if(i!=f){
            dep[i]=dep[u]+1;
            init(i,u);
            len[u]=max(len[i]+1,len[u]);
            if(len[i]>mx){
                smx=mx;
                mx=len[i];
            }else if(len[i]>smx){
                smx=len[i];
            }
        }
        vector<int> ngr;
        ngr.reserve(gr[u].size());
        for(auto&i:gr[u]) if(i!=f&&len[i]==mx) ngr.emplace_back(i);
        for(auto&i:gr[u]) if(i!=f&&len[i]<mx&&len[i]==smx) ngr.emplace_back(i);
        for(auto&i:gr[u]) if(i!=f&&len[i]<smx) ngr.emplace_back(i);
        if(~f) ngr.emplace_back(f);
        gr[u]=move(ngr);
    }
    auto calccst(int u,int f=-1)->void{
        cnt[u]=0;
        for(auto&i:gr[u]) if(i!=f){
            calccst(i,u);
            cnt[u]+=cnt[i];
        }
        cnt[u]+=len[u]>req-1;
    }
    auto calcsub(int u,int t,int f=-1)->void{
        auto valid=[&](int x){
            if(gr[x].empty()||gr[x][0]==uf[x]) return false;
            return (((gr[x].size()>1&&gr[x][1]!=uf[x])?len[gr[x][1]]+1:0)+dep[t]-dep[u]+1<req+1);
        };
        if(dep[u]>dep[t]) t=u;
        while(valid(t)) t=gr[t][0];
        sub[u]=t;
        for(auto&i:gr[u]) if(i!=f&&len[i]>req) calcsub(i,t,u);
    }
    auto calcchk(int u,int f=-1)->int{
        vector<int> px;
        auto mxdis=0;
        for(auto&i:gr[u]) if(i!=f){
            const auto z=calcchk(i,u);
            cst[u]+=cst[i];
            if(~z) px.emplace_back(z);
            else mxdis=max(mxdis,len[i]+1);
        }
        if(px.empty()&&len[u]>req-1){
            px.emplace_back(u);
            ++cst[u];
        }
        if(px.size()>1){
            for(auto&x:px) cst[u]+=dep[x]-dep[u];
            ++cst[u];
            px={u};
        }else while(px.size()==1&&dep[px[0]]-dep[u]+mxdis>req){
            px[0]=uf[px[0]];
            ++cst[u];
        }
        return px.empty()?-1:px[0];
    }
public:
    auto link(int u,int v){
        gr[u].emplace_back(v);
        gr[v].emplace_back(u);
    }
    auto initrt(int rt){
        dep[rt]=0;
        init(rt);
    }
    auto calc(int rt,int _req){
        req=_req;
        calccst(rt);
        fill(sub.begin(),sub.end(),-1);
        fill(cst.begin(),cst.end(),0);
        calcsub(rt,rt);
        calcchk(rt);
        auto ans=cnt[rt];
        rep(i,0,(int)(gr.size())) if(~sub[i]){
            ans=min(ans,max(cnt[rt]-cnt[i],1)+max(cst[sub[i]],1));
        }
        return ans;
    }
    chk_tree(int _n):gr(_n),len(_n),cnt(_n),sub(_n),dep(_n),cst(_n),uf(_n){}
};
int main(){
    ios::sync_with_stdio(false),inf.tie(nullptr);
    int c,T;inf>>c>>T;
    while(T--) []{
        int n,k;inf>>n>>k;
        tree gr(n);
        chk_tree cgr(n);
        rep(i,0,n-1){
            int u,v;inf>>u>>v;--u;--v;
            gr.link(u,v);
            cgr.link(u,v);
        }
        if(n==k) return ouf<<0<<'\n',void();
        const auto path=gr.d();
        auto l=1,r=n-1,ans=n-1;
        while(l-1<r){
            const auto mid=(l+r)/2;
            if(mid*2>(int)(path.size()-1)-1){
                r=mid-1;
                ans=mid;
            }else{
                cgr.initrt(path[mid]);
                const auto wx=cgr.calc(path[mid],mid);
                cgr.initrt(path[(path.size()-1)-mid]);
                const auto wy=(wx<k+1?wx:cgr.calc(path[(path.size()-1)-mid],mid));
                (min(wx,wy)<k+1)?((r=mid-1),(ans=mid)):(l=mid+1);
            }
        }
        ouf<<ans<<'\n';
    }();
    return 0;
}