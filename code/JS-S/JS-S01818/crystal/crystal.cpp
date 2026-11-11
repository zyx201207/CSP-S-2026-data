#include<bits/stdc++.h>
#define int long long
#define r(x) x=read()
#define w(x) write(x)
#define sp putchar(' ')
#define en putchar('\n')
using namespace std;
int read(){int x=0,f=1;char ch=getchar();while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x*f;}
void write(int x){if(x<0) x=-x,putchar('-');if(x>9) write(x/10);putchar(x%10^48);}
const int N=5e5+10;
int a[N];
struct node{
    int l,r,w,tage;
}t[N<<3];
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
    //cerr<<u<<':'<<l<<' '<<r<<endl;
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
int n,m;
bool check(int mid,int i){
    return query(1,mid,i-1)<=m;
}
bool checka(){
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=a[2]-a[1]) return 0;
    }
    return 1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    r(n),r(m);
    for(int i=1;i<=n;i++) r(a[i]);
    build(1,1,n);
    sort(a+1,a+1+n);
    if(checka()){
        int d=a[2]-a[1];
        int l=1,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(mid*(mid-1)/2*d<=m) l=mid+1;
            else r=mid-1;
        }
        w(l-1),en;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i-1;
        update(1,1,i-1,a[i]-a[i-1]);
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,i)) r=mid-1;
            else l=mid+1;
        }
        r++;
        //cerr<<r<<" is Ok,the length is "<<i-r+1<<endl;
        //cout<<i<<":\n";
        //for(int j=1;j<=i;j++){
        //    cout<<j<<"~"<<i<<'='<<query(1,j,i)<<endl;
        //}
        //cout<<endl;
        ans=max(ans,i-r+1);
    }
    w(ans);
    return 0;
}
/*
5 13
0 7 14 21 28
*/
