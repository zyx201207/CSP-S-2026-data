#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define debug1(x) cerr<<(#x)<<"="<<(x)<<" "
#define debug2(x) cerr<<(#x)<<"="<<(x)<<"\n"
template<class T>
inline void operator += (vector<T>&x,const T &y){x.emplace_back(y);}
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
int ld(int l,int r){return (int)(rnd()%(r-l+1)+l);}
namespace ARIS2_0{
    namespace exstd{
        constexpr int maxs=4e6+10;
        struct sgmtree{
            #define ls(id) ((id)<<1)
            #define rs(id) (((id)<<1)|1)
            #define inr(l,r,cl,cr) ((cl)<=(l) and (r)<=(cr))
            pii w[maxs];
            int tag[maxs];
            //w 存，加上 tag 之后的东西
            void pushup(int id){
                w[id]=max(w[ls(id)],w[rs(id)]);
                w[id].fi+=tag[id];
            }
            void build(int id,int l,int r,int *a){
                tag[id]=0;
                if(l==r){
                    w[id]=mp(a[l],l);
                    return;
                }
                int mid=(l+r)>>1;
                build(ls(id),l,mid,a);
                build(rs(id),mid+1,r,a);
                pushup(id);
            }
            void update(int id,int l,int r,int cl,int cr,int pos){
                // debug1(id);debug1(l);debug1(r);debug1(cl);debug2(cr);
                if(inr(l,r,cl,cr)){
                    w[id].fi+=pos;
                    tag[id]+=pos;
                    // debug2(w[id].fi);
                    return;
                }
                int mid=(l+r)>>1;
                if(cl<=mid)update(ls(id),l,mid,cl,cr,pos);
                if(cr>mid)update(rs(id),mid+1,r,cl,cr,pos);
                pushup(id);
            }
        };
    }
    exstd::sgmtree t;
    constexpr int maxn=1e6+10;
    vector<int>v[maxn];
    int n,k,fa[maxn],leaftot=0;
    int L[maxn],R[maxn],dep[maxn],val[maxn],r1[maxn],r2[maxn];
    void dfs(int x,int SP){
        int cnt=0;
        for(int y:v[x]){
            if(y!=fa[x] and y!=SP){
                cnt++;
                fa[y]=x;
                dep[y]=dep[x]+1;
                dfs(y,SP);
                L[x]=min(L[x],L[y]);
                R[x]=max(R[x],R[y]);
            }
        }
        if(!cnt){
            L[x]=R[x]=++leaftot;
            val[leaftot]=dep[x];
        }
    }
    void dfs_fa(int x){
        for(int y:v[x]){
            if(y!=fa[x]){
                fa[y]=x;
                dfs_fa(y);
            }
        }
    }
    struct node{
        int id,l,r;
    };
    inline bool operator < (const node &pa,const node &pb){return pa.l<pb.l;}
    set<node>s;
    void solve(int rt,int SP,int *r){
        bool DEBUG=(rt==2 and SP==0);
        //[1,leaftot] 有 val
        //从 rt 开始每次可以向下
        t.build(1,1,leaftot,val);
        // debug1(leaftot);
        s.clear();
        for(int pr:v[rt]){
            if(pr!=fa[rt] and pr!=SP){
                s.insert(node{pr,L[pr],R[pr]});
            }
        }
        for(int i=1;i<=k;i++){
            //统计当前贡献
            pii pos=t.w[1];
            if(pos.fi==0){
                for(int j=i;j<=k;j++){
                    r[j]=0;
                }
                break;
            }
            //fi dep 大小 se 编号
            r[i]=pos.fi;
            // debug1(i);debug2(pos.fi);
            if(i==k)break;
            //考虑更新一个点
            //那么就是把 pos.se 减掉
            /*if(DEBUG){
                debug1(pos.fi);debug2(pos.se);
            }*/
            auto it=s.upper_bound(node{0,pos.se,0});
            assert(it!=s.begin());
            it--;
            int id=(*it).id;
            s.erase(it);
            t.update(1,1,leaftot,L[id],R[id],-1);
            // debug1(L[id]);debug2(R[id]);
            for(int pr:v[id]){
                if(pr!=fa[id] and pr!=SP){
                    s.insert(node{pr,L[pr],R[pr]});
                }
            }
        }
    }
    int PP[maxn];
    void D(int x,int val,int p1,int p2,int p3){
        if(x==p1 or x==p2 or x==p3)return;
        PP[x]=min(PP[x],val);
        for(int y:v[x]){
            if(y!=p1 and y!=p2 and y!=p3){
                D(y,val+1,p1,p2,x);
            }
        }
    }
    bool SP1=0,SP2=0;
    int cnt1=0,cnt2=0;
    inline int nxt1(const int &x,const int &l,const int &r){
        if(!SP1){
            if(x==r)return 0;
            return x+1;
        }
        cnt1++;
        if(cnt1==150)return 0;
        return ld(l,r);
    }
    inline int nxt2(const int &x,const int &l,const int &r){
        if(!SP2){
            if(x==r)return 0;
            return x+1;
        }
        cnt2++;
        if(cnt2==5)return 0;
        return ld(l,r);
    }
    void solve(){
        cnt1=0;cnt2=0;
        // debug2(SP1);
        // exit(0);
        cin>>n>>k;
        for(int i=1;i<=n;i++)v[i].clear();
        for(int i=1,x,y;i<n;i++){
            cin>>x>>y;
            v[x]+=y;
            v[y]+=x;
        }
        int ans=n,p1=1;
        while(p1){
            for(int i=1;i<=n;i++)fa[i]=0;
            dfs_fa(p1);
            int p2=p1+1;
            while(p2){
                for(int i=1;i<=n;i++)PP[i]=n+10;
                int pos=p2;
                while(fa[pos]!=p1)pos=fa[pos];
                //p2 first
                leaftot=0;
                for(int i=1;i<=n;i++)L[i]=n,R[i]=1;
                dep[p2]=0;
                dfs(p2,0);
                solve(p2,0,r1);

                leaftot=0;
                for(int i=1;i<=n;i++)L[i]=n,R[i]=1;
                dep[p1]=0;
                dfs(p1,pos);
                solve(p1,pos,r2);

                int rans=n;
                for(int i=1;i<k;i++){
                    /*if(p1==1 and p2==2 and rans and max(r1[i],r2[k-i])==0){
                        debug1(i);debug1(r1[i]);debug2(r2[k-i]);
                    }*/
                    rans=min(rans,max(r1[i],r2[k-i]));
                }
                //rans 还要修正的，具体而言要考虑 pos 子树去掉 y 子树
                D(pos,1,p1,p2,0);D(fa[p2],1,p1,p2,0);
                for(int i=1;i<=n;i++){
                    if(PP[i]<n)rans=max(rans,PP[i]);
                }
                /*if(ans and !rans){
                    debug1(p1);debug2(p2);
                }*/
                ans=min(ans,rans);
                /*if(p1==1 and p2==2){
                    cerr<<"STOP\n";
                    debug2(ans);
                    exit(0);
                }*/

                p2=nxt2(p2,p1+1,n);
                // debug1(p1);debug2(p2);
            }
            p1=nxt1(p1,1,n-1);
        }
        cout<<ans<<"\n";
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,T=1;
    cin>>c>>T;
    if(c>=7)ARIS2_0::SP1=1;
    if(c>=11)ARIS2_0::SP2=1;
    while(T--)ARIS2_0::solve();
}