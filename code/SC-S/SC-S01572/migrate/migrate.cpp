#include<bits/stdc++.h>
using namespace std;
#define db(x...) fprintf(stderr,x)
using ll=long long;
const int N=2e6+5;
int n,tid;
ll a[N],d;
int nex[N];
vector<int> e[N];
namespace BF{
    int cnt[N];
    int s;
    ll ans;
    inline void add(int c,int w){
        s-=(cnt[c]==1),cnt[c]+=w,s+=(cnt[c]==1);
    }
    void modif(int x,int y,int w){
        while(1){
            int p=nex[x],q=nex[y];
            if(max(x+1,y+1)>min(p,q)) break;
            for(int i=max(x+1,y+1);i<=min(p,q);++i) add(i,w);
            x=p,y=q;
        }
    }
    void dfs(int u){
        ans+=s;
        if(u>1) modif(u,u-1,1);
        if(u>2) modif(u,u-2,1);
        for(auto v:e[u]) dfs(v);
        if(u>1) modif(u,u-1,-1);
        if(u>2) modif(u,u-2,-1);
    }

    ll slv(){
        ans=0;
        for(int i=1;i<=n;++i) e[i].clear();
        for(int i=n,j=n;i;--i){
            while(a[j]-a[i]>d) --j;
            nex[i]=j;
            if(i!=nex[i]) e[nex[i]].push_back(i);
        }
        for(int i=1;i<=n;++i) cnt[i]=0;
        for(int i=1;i<=n;++i)
            if(nex[i]==i) dfs(i);
        return ans;
    }
}
namespace spec{
    ll ans;
    ll slv(){
        ans=0;
        for(int i=n,j=n;i;--i){
            while(a[j]-a[i]>d) --j;
            nex[i]=j;
        }
        for(int i=1;i<=n;++i)
            if(nex[i]!=i&&nex[nex[i]]!=nex[i]){
                //(nex,nexnex]
                int l=nex[i]+1,r=min(nex[nex[i]],nex[nex[i]-1]);
                if(nex[i]-2>i) l=max(l,nex[nex[i]-2]+1);
                ans+=max(r-l+1,0);
            }
        return ans;
    }
}
namespace spec2{
    const int D=22,R=8005;
    ll ans;
    struct node{ int p,w; }stk[D][R],tmp[R];
    int top[D];
    int calc(int dep){
        int s=0,ans=0;
        for(int i=1;i<=top[dep];){
            int j=i;
            while(j<=top[dep]&&stk[dep][i].p==stk[dep][j].p) s+=stk[dep][j++].w;
            if(s==1) ans+=stk[dep][j].p-stk[dep][i].p;//,db("%d %d\n",stk[dep][i].p,stk[dep][j].p-1);
            i=j;
        }
        return ans;
    }
    int ct;
    void modif(int x,int y){
        while(1){
            int p=nex[x],q=nex[y];
            if(max(x+1,y+1)>min(p,q)) break;
            tmp[++ct]={max(x+1,y+1),1},tmp[++ct]={min(p,q)+1,-1};
            // db("[%d %d]\n",max(x+1,y+1),min(p,q));
            x=p,y=q;
        }
    }
    inline bool cmp(node &a,node &b){ return a.p<b.p; }
    void merge(int dep){
        // db("merge---\n");
        // for(int i=1;i<=ct;++i) db("(%d,%d)%c",tmp[i].p,tmp[i].w," \n"[i==ct]);
        // for(int i=1;i<=top[dep-1];++i) db("(%d,%d)%c",stk[dep-1][i].p,stk[dep-1][i].w," \n"[i==top[dep-1]]);
        sort(tmp+1,tmp+ct+1,cmp);
        int x=1,y=1;
        top[dep]=0;
        while(x<=ct||y<=top[dep-1]){
            if(x<=ct&&(y>top[dep-1]||stk[dep-1][y].p>tmp[x].p)){
                stk[dep][++top[dep]]=tmp[x++];
            }else{
                stk[dep][++top[dep]]=stk[dep-1][y++];
            }
        }
        // for(int i=1;i<=top[dep];++i) db("(%d,%d)%c",stk[dep][i].p,stk[dep][i].w," \n"[i==top[dep]]);
    }
    void dfs(int u,int dep){
        // db("------ %d %d-----\n",u,dep);
        ans+=calc(dep-1);
        ct=0;
        if(u>1) modif(u,u-1);
        if(u>2) modif(u,u-2);
        // db("%d!!\n",dep);
        merge(dep);
        for(auto v:e[u]) dfs(v,dep+1);//,db("%d to %d\n",u,v);
        // db("-------\n");
    }

    ll slv(){
        ans=0;
        for(int i=1;i<=n;++i) e[i].clear();
        for(int i=n,j=n;i;--i){
            while(a[j]-a[i]>d) --j;
            nex[i]=j;
            if(i!=nex[i]) e[nex[i]].push_back(i);
        }
        top[0]=0;
        for(int i=1;i<=n;++i)
            if(nex[i]==i) dfs(i,1);
        return ans;
    }
}
void slv(){
    cin>>n>>d;
    for(int i=1;i<=n;++i) cin>>a[i];
    if(tid==13||tid==14) printf("%lld\n",spec::slv());
    else if(15<=tid&&tid<=18) printf("%lld\n",spec2::slv());
    else printf("%lld\n",BF::slv());
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int T;
    cin>>tid>>T;
    while(T--) slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}