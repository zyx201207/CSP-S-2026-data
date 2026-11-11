#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int N=2e6+5;
int c,T,n,pos[N];
ll d,x[N],ans;

struct IO{
    static constexpr size_t V=1<<20;
    char ibuf[V],obuf[V],stk[30];
    size_t pi,po,len,top;

    void flush(){
        cout.write(obuf,po), po=0;
    }
    ~IO(){
        flush();
    }
    char gc(){
        if(pi==len) cin.read(ibuf,V), len=cin.gcount(), pi=0;
        return len?ibuf[pi++]:0;
    }
    void pc(char ch){
        if(po==V) flush();
        obuf[po++]=ch;
    }

    void read(int& x){
        char ch=gc();
        x=0;
        while(ch<'0'||ch>'9') ch=gc();
        while(ch>='0'&&ch<='9') x=x*10+(ch^48), ch=gc();
    }
    void read(ll& x){
        char ch=gc();
        int f=0;
        x=0;
        while(ch<'0'||ch>'9') f|=(ch=='-'), ch=gc();
        while(ch>='0'&&ch<='9') x=x*10+(ch^48), ch=gc();
        x=(f?-x:x);
    }
    void write(ll x){
        if(!x) pc('0');
        while(x) stk[++top]=x%10^48, x/=10;
        while(top) pc(stk[top--]);
        pc('\n');
    }
}io;

struct Node{
    int dis,cnt;
    Node(int a=N,int b=0):dis(a),cnt(b) {}
    Node operator +(const Node& x)const{
        if(dis==x.dis) return Node(dis,min(3,cnt+x.cnt));
        return dis<x.dis?Node(dis,cnt):x;
    }
};

namespace seg{
    #define li (i<<1)
    #define ri (i<<1|1)
    #define mid (l+r>>1)

    Node tag[N<<2],t[N<<2];

    void lazy(int i,const Node& v){
        t[i]=t[i]+v, tag[i]=tag[i]+v;
    }
    void down(int i){
        if(tag[i].cnt) lazy(li,tag[i]), lazy(ri,tag[i]), tag[i]=Node();
    }
    void upd(int p,int q,const Node& v,int l,int r,int i){
        if(p<=l&&r<=q) return lazy(i,v);
        down(i);
        if(p<=mid) upd(p,q,v,l,mid,li);
        if(q>mid) upd(p,q,v,mid+1,r,ri);
    }
    Node query(int p,int l,int r,int i){
        while(l<r){
            down(i);
            if(p<=mid) r=mid, i=li;
            else l=mid+1, i=ri;
        }
        return t[i];
    }
    void cal(int l,int r,int i){
        if(l==r){
            ans+=(t[i].cnt==2);
            t[i]=tag[i]=Node();
            return;
        }
        down(i), t[i]=Node();
        cal(l,mid,li), cal(mid+1,r,ri);
    }

    #undef mid
}

void sol(){
    io.read(n), io.read(d);
    for(int i=1;i<=n;i++)
        io.read(x[i]);
    for(int i=1, j=1;i<=n;i++){
        while(j<n&&x[j+1]-x[i]<=d) j++;
        pos[i]=j;
    }

    ans=0;
    if(n<=5000){
        for(int i=1;i<=n;i++){
            seg::upd(i,i,Node(0,1),i,n,1);
            for(int j=i;j<=n;j++){
                Node cur=seg::query(j,i,n,1);
                cur.dis++;
                if(j+1<=pos[j]) seg::upd(j+1,pos[j],cur,i,n,1);
            }
            seg::cal(i,n,1);
        }
    }
    io.write(ans);
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    io.read(c), io.read(T);
    while(T--) sol();
    return 0;
}
