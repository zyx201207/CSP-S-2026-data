#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define fi first
#define se second
#define pb push_back
#define v(x) vector<x>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=1000010;
int read(){
    int x=0;
    bool f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=0;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return f?x:-x;
}
int ID,T;
int n,m;
v(int)v[N];
int f[N][2],mxd[N],mx[N],mx2[N];
int fr[N],e1,e2,rt;
void dfs(int now,int fa){
    if(mxd[now]>mxd[e1]) e1=now;
    for(int t:v[now])if(t!=fa){
        mxd[t]=mxd[now]+1;
        dfs(t,now);
    }
}
void dfsy(int now,int fa){
    mxd[now]=0;
    for(int t:v[now])if(t!=fa){
        dfsy(t,now);
        mxd[now]=max(mxd[now],mxd[t]+1);
    }
}
void dfs2(int now,int fa,int k,int xs,int umax){
    f[now][0]=f[now][1]=mx[now]=mx2[now]=0;
    if(mxd[now]<k) return ;
    for(int t:v[now])if(t!=fa){
        dfs2(t,now,k);
        f[now][0]+=f[t][1];
        if(mxd[t]+1>mx[now]) mx2[now]=mx[now],mx[now]=mxd[t]+1;
        else if(mxd[t]+1>mx2[now]) mx2[now]=mxd[t]+1; 
    }
    f[now][1]=f[now][0]+1;
    if(mx2[now]>=k) f[now][0]++;
}
int ans;
void dfs3(int now,int fa,int k,int sum,int xs,int umx){
    ans=min(ans,max(1,sum)+max(1,f[now][0]));
    // cout<<now<<":"<<sum<<"\n";
    bool bl=0;
    if(umx>=k) bl=1;
    if(fa!=0) umx++;
    int lx=xs,ls=sum;
    for(int t:v[now])if(t!=fa){
        int d=mxd[t]+1;
        d=(d==mx[now]?mx2[now]:mx[now]);
        int u2=max(umx,d);
        xs=lx,sum=ls;
        if(u2<k) {
            dfs3(t,now,k,sum,0,u2);
        }else if(bl==0&&u2>=k) {
            dfs3(t,now,k,sum+f[now][1]-f[t][1],0,u2);
        }else {
            xs++;
            if(d+xs<=k) dfs3(t,now,k,sum,xs,u2);
            else if(d<k) dfs3(t,now,k,sum+xs-(k-d),k-d,u2);
            else dfs3(t,now,k,sum+xs+f[now][1]-1-f[t][1],0,u2);
        }
    }
}
bool check(int k){
    ans=n;
    dfs2(rt,0,k);
    dfs3(rt,0,k,0,0,0);
    return ans<=m;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ID=read(),T=read();
    while(T--){
        n=read(),m=read();
        for(int i=1;i<=n;i++){
            v[i].clear();
        }
        for(int a,b,i=1;i<n;i++){
            a=read(),b=read();
            v[a].pb(b),v[b].pb(a);
        }
        if(m==n){
            puts("0");
            continue;
        }
        e1=1;
        dfs(1,0);
        rt=e1;
        dfsy(rt,0);
        int l=1,r=n-1,mid,ans=0;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}