#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const long long INF=1e18;
const long long Max=10;
int c,T;
int n;
long long d;
long long x[N];
long long ans=0;
struct Pair{
    long long f;
    long long g;
    Pair operator+(const Pair &other)const{
        Pair res={INF,0};
        if(f<other.f){
            res.g=g;
        }
        else if(f==other.f){
            res.g=g+other.g;
            if(res.g>Max)res.g=Max;
        }
        else{
            res.g=other.g;
        }
        res.f=min(f,other.f);
        return res;
    }
}f[N];
struct Segment_tree{
    Pair val[N<<2];
    void clear(){
        for(int i=1;i<(N<<2);i++){
            val[i]={INF,0};
        }
    }
    void push_up(int v){
        val[v]=val[v<<1]+val[v<<1|1];
    }
    void modify(int v,int l,int r,int x,Pair h){
        if(l==r){
            val[v]=h;
            return;
        }
        int mid=(l+r)>>1;
        if(x<=mid)modify(v<<1,l,mid,x,h);
        else modify(v<<1|1,mid+1,r,x,h);
        push_up(v);
    }
    Pair query(int v,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            return val[v];
        }
        int mid=(l+r)>>1;
        Pair res={INF,0};
        if(L<=mid)res=res+query(v<<1,l,mid,L,R);
        if(mid<R)res=res+query(v<<1|1,mid+1,r,L,R);
        return res;
    }
}Segtree;
void solve1(){
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int s=1;s<=n;s++){
        Segtree.clear();
        f[s]={0,1};
        Segtree.modify(1,1,n,s,f[s]);
        for(int t=s+1;t<=n;t++){
            int L=lower_bound(x+1,x+n+1,max(x[t]-d,x[s]))-x;
            f[t]=Segtree.query(1,1,n,L,t);
            f[t].f++;
            Segtree.modify(1,1,n,t,f[t]);
            if(f[t].g==2){
                ans++;
            }
            f[t]={INF,0};
        }
    }
    cout<<ans<<'\n';
    return;
}
void solve2(){
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    Segtree.clear();
    f[1]={0,1};
    Segtree.modify(1,1,n,1,f[1]);
    for(int t=2;t<=n;t++){
        int L=lower_bound(x+1,x+n+1,max(x[t]-d,x[1]))-x;
        f[t]=Segtree.query(1,1,n,L,t);
        f[t].f++;
        Segtree.modify(1,1,n,t,f[t]);
        if(f[t].g==2){
            ans+=n-t+1;
        }
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        if(c<=10){
            solve1();
        }
        else if(c<=12){
            solve2();
        }
        else{
            solve1();
        }
    }
    return 0;
}