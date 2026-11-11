// #define DEBUG
#include<bits/stdc++.h>
using namespace std;
ifstream fin("crystal.in");
ofstream fout("crystal.out");
#ifdef DEBUG
#define fin cin
#define fout cout
#endif
using i64=long long;
using f64=double;
using pii=pair<int,int>;
using vci=vector<int,int>;
#define pbk push_back
#define ctn continue
#define rtn return
#define brk break
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define pre(i,a,b) for(int i=(a);i>=(b);--i)
#define re(i,a) for(int i=1;i<=(a);++i)
#define rel(i,a) for(int i=0;i<(a);++i)
#define chmn(a,b) a=min((a),(b))
#define chmx(a,b) a=max((a),(b))
/*--------------------------------------------------------*/
#define lc (u<<1)
#define rc (u<<1|1)
struct Segnode{
    i64 sum,lazy_add;
    Segnode operator+(const Segnode&rhs)const{
        rtn {sum+rhs.sum,0};
    }
};
const int MAXN=1e5+8;
struct Segment{
    Segnode tr[MAXN<<1];
    int lb[MAXN<<1],rb[MAXN<<1];
    void push_up(int u){tr[u]=tr[lc]+tr[rc];}
    void push_down(int u){
        if(!tr[u].lazy_add)rtn;
        tr[lc].sum+=tr[u].lazy_add*(rb[lc]-lb[lc]+1);
        tr[lc].lazy_add+=tr[u].lazy_add;
        tr[rc].sum+=tr[u].lazy_add*(rb[rc]-lb[rc]+1);
        tr[rc].lazy_add+=tr[u].lazy_add;
        tr[u].lazy_add=0;
    }
    void build(int u,int l,int r,i64 val[MAXN]={}){
        lb[u]=l;rb[u]=r;
        if(l==r){
            tr[u].sum=val[l];
            rtn;
        }int mid=l+r>>1;
        build(lc,l,mid,val);build(rc,mid+1,r,val);
        push_up(u);
    }
    void add(int u,int l,int r,i64 val){
        if(l>rb[u]||r<lb[u]||l>r)rtn;
        if(l<=lb[u]&&rb[u]<=r){
            tr[u].sum+=val*(rb[u]-lb[u]+1);
            tr[u].lazy_add+=val;
            rtn;
        }push_down(u);
        add(lc,l,r,val);add(rc,l,r,val);
        push_up(u);
    }
    Segnode query(int u,int l,int r){
        if(l>rb[u]||r<lb[u]||l>r)rtn {0,0};
        if(l<=lb[u]&&rb[u]<=r)rtn tr[u];
        push_down(u);
        rtn query(lc,l,r)+query(rc,l,r);
    }
};
int n;
i64 m,a[500010],s[500010];
int main(){
    fin>>n>>m;
    re(i,n)fin>>a[i];
    sort(a+1,a+n+1);
    re(i,n)s[i]=s[i-1]+a[i];
    int ans=0;
    re(i,n){
        int l=1,r=i;
        while(l<r){
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)r=mid;
            else l=mid+1;
        }
        chmx(ans,i-l+1);
    }fout<<ans;
}
