#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e6+10;
char buf[1<20],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
ll read(){
    char ch=getchar();ll x=0,f=1;
    while(!isdigit(ch)){if(ch=='-') x=-x;ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
void write(ll x){
    if(x<0) putchar('-'),x=-x;
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}
int n;
ll d;
int L[MAXN],R[MAXN];
ll a[MAXN];
struct node{
    int l,r;
}e[MAXN];
int ok[MAXN];
ll rs;
int lx[MAXN],rx[MAXN];
void work(int l,int r){
    int posl=l,posr=l;
    for(int i=l;i<=r;i++){
        while(posl<=r&&L[posl]<i-1) posl++;
        while(posr<r&&L[posr+1]<=i-1) posr++;
        lx[i]=max(i+1,posl),rx[i]=posr;
    }
    for(int i=l;i<r;i++){
        int u=i;
        ok[i]=1;ok[i-1]=0;
        while(u!=r){
            int l1=lx[u],r1=rx[u];
            if(u==i) l1=i+1;
            if(ok[u-1]+ok[u]==2) rs+=(r1-l1+1);
            int l2=rx[u]+1,r2=R[u];
            if(ok[u]==2) rs+=(r2-l2+1);
            auto work=[&](int x){
                if(l2<=x&&x<=r2) ok[x]=ok[u];
                else if(l1<=x&&x<=r1) ok[x]=ok[u]+ok[u-1];
                else ok[x]=3;
            };
            work(R[u]);
            if(R[u]!=u+1) work(R[u]-1);
            u=R[u];
        }u=i;
        while(u!=r) ok[u]=ok[u-1]=0,u=R[u];
    }
}
void work2(int l,int r){
    int posl=l,posr=l;
    for(int i=l;i<=r;i++){
        while(posl<=r&&L[posl]<i-1) posl++;
        while(posr<r&&L[posr+1]<=i-1) posr++;
        lx[i]=max(i+1,posl),rx[i]=posr;
    }
    for(int i=l;i<r;i++){
        int u=i;
        ok[i]=1;ok[i-1]=0;int cnt=10;
        while(u!=r&&cnt){
            int l1=lx[u],r1=rx[u];
            if(u==i) l1=i+1;
            if(ok[u-1]+ok[u]==2) rs+=(r1-l1+1);
            int l2=rx[u]+1,r2=R[u];
            if(ok[u]==2) rs+=(r2-l2+1);
            auto work=[&](int x){
                if(l2<=x&&x<=r2) ok[x]=ok[u];
                else if(l1<=x&&x<=r1) ok[x]=ok[u]+ok[u-1];
                else ok[x]=3;
            };
            work(R[u]);cnt--;
            if(R[u]!=u+1) work(R[u]-1);
            u=R[u];
        }u=i;cnt=20;
        while(u!=r&&cnt) ok[u]=ok[u-1]=0,u=R[u],cnt--;
    }
}
void work3(int l,int r){
    int posl=l,posr=l;
    for(int i=l;i<=r;i++){
        while(posl<=r&&L[posl]<i-1) posl++;
        while(posr<r&&L[posr+1]<=i-1) posr++;
        lx[i]=max(i+1,posl),rx[i]=posr;
    }
    for(int i=l;i<r;i++){
        int u=i;
        ok[i]=1;ok[i-1]=0;int cnt=800;
        while(u!=r&&cnt){
            int l1=lx[u],r1=rx[u];
            if(u==i) l1=i+1;
            if(ok[u-1]+ok[u]==2) rs+=(r1-l1+1);
            int l2=rx[u]+1,r2=R[u];
            if(ok[u]==2) rs+=(r2-l2+1);
            auto work=[&](int x){
                if(l2<=x&&x<=r2) ok[x]=ok[u];
                else if(l1<=x&&x<=r1) ok[x]=ok[u]+ok[u-1];
                else ok[x]=3;
            };
            work(R[u]);cnt--;
            if(R[u]!=u+1) work(R[u]-1);
            u=R[u];
        }u=i;cnt=800;
        while(u!=r&&cnt) ok[u]=ok[u-1]=0,u=R[u],cnt--;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;cin>>c>>T;
    while(T--){
        cin>>n>>d;rs=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        int pos=0;
        for(int i=1;i<=n;i++){
            while(pos<n&&a[pos+1]-a[i]<=d) pos++;
            R[i]=pos;
        }pos=n;
        for(int i=n;i>=1;i--){
            while(pos>1&&a[i]-a[pos-1]<=d) pos--;
            L[i]=pos;
        }int tot=1;e[1].l=1;
        for(int i=1;i<=n;i++){
            if(R[i]==i) e[tot].r=i,e[++tot].l=i+1;
        }--tot;
        if(c>=11&&c<=12) for(int i=1;i<=tot;i++) work2(e[i].l,e[i].r);
        else if(c>=19) for(int i=1;i<=tot;i++) work3(e[i].l,e[i].r);
        else for(int i=1;i<=tot;i++) work(e[i].l,e[i].r);
        cout<<rs<<'\n';
    }
    return 0;
}