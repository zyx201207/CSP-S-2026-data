#include<bits/stdc++.h>
#define int long long
#define r(x) x=read()
#define w(x) write(x)
#define sp putchar(' ')
#define en putchar('\n')
using namespace std;
int read(){int x=0,f=1;char ch=getchar();while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x*f;}
void write(int x){if(x<0) x=-x,putchar('-');if(x>9) write(x/10);putchar(x%10^48);}
const int N=2e6+10;
struct node{
    int l,r,w,tage;
}t[N<<2];
void push_up(int u){
    t[u].w=t[u*2].w+t[u*2+1].w;
}
void push_down(int u){
    t[u*2].w+=(t[u*2].r-t[u*2].l+1)*t[u].tage;
    t[u*2].tage+=t[u].tage;
    t[u*2+1].w+=(t[u*2+1].r-t[u*2+1].l+1)*t[u].tage;
    t[u*2+1].tage+=t[u].tage;
    t[u].tage=0;
}
void build(int u,int l,int r){
    t[u].l=l,t[u].r=r,t[u].tage=0;
    if(l==r){
        t[u].w=0;
        return ;
    }
    int mid=(l+r)/2;
    build(u*2,l,mid);
    build(u*2+1,mid+1,r);
    push_up(u);
}
void update(int u,int l,int r,int k){
    if(l<=t[u].l&&t[u].r<=r){
        t[u].w+=(t[u].r-t[u].l+1)*k;
        t[u].tage+=k;
        return ;
    }
    int mid=(t[u].l+t[u].r)/2;
    push_down(u);
    if(l<=mid) update(u*2,l,r,k);
    if(r>mid) update(u*2+1,l,r,k);
    push_up(u);
}
int query(int u,int l,int r){
    if(l<=t[u].l&&t[u].r<=r){
        return t[u].w;
    }
    int mid=(t[u].l+t[u].r)/2,ans=0;
    push_down(u);
    if(l<=mid) ans+=query(u*2,l,r);
    if(r>mid) ans+=query(u*2+1,l,r);
    return ans;
}
int n,d;
int a[N];
int dp[N];
int r[N];
void solve(){
    bool checka=1;
    r(n),r(d);
    for(int i=1;i<=n;i++){
        r(a[i]);
        if(checka){
            if(i>1){
                if(a[i]-a[i-1]!=a[2]-a[1]) {
                    //cout<<a[i]-a[i-1]<<' '<<a[2]-a[1]<<endl;
                    //cout<<i<<" hacks the A\n";
                    checka=0;
                }

            }
        }
    }
    if(checka){
        int k=d/(a[2]-a[1]);
        int ans=n-2*k+1;
        if(k==0||k==1||ans<0) ans=0;
        /*w(d),sp,w(a[2]-a[1]),sp,w(k),sp,*/w(ans),en;
        return ;
    }
    for(int i=1;i<=n;i++){
        r[i]=n;
        while(a[r[i]]-d>a[i]) r[i]--;
    }
    //cout<<"Not A\n";
    int ans=0;
    for(int u=1;u<=n;u++){
        for(int v=u;v<=n;v++){
            build(1,1,n);
            if(a[v]-a[u]<=d) continue;
            for(int i=u;i<=v;i++){
                update(1,i+1,r[i],1);
            }
            //cout<<u<<' '<<v<<':'<<query(1,v,v)<<endl;
            if(query(1,v,v)==2) ans++;
        }
    }
    w(ans),en;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int r(c),r(T);while(T--) solve();
    return 0;
}
