#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int test,T,n,k,a,b,mx,rt,dep[N],f[N][2],g[N][2],h[N],c[N],ans;
vector<int>e[N];
int read(){
    int k=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
        k=k*10+ch-'0',ch=getchar();
    return k*f;
}
void dfs1(int x,int y){
    f[x][0]=0,f[x][1]=0;
    g[x][0]=x,g[x][1]=x;
    for(int i:e[x]){
        if(i==y||((x==a&&i==b)||(x==b&&i==a)))
            continue;
        dfs1(i,x);
        int t=f[i][0]+1,id=i;
        for(int j=0;j<2;j++){
            if(t>=f[x][j]){
                swap(f[x][j],t);
                swap(g[x][j],id);
            }
        }
    }
}
void dfs2(int x,int y){
    if(y==0)
        h[x]=-n;
    // cout<<x<<" "<<f[x][0]<<" "<<h[x]<<endl;
    int t=f[x][0];
    if(y) t=min(t,h[x]);
    else{
        if(e[x].size()==2)
            t=0;
    }
    if(mx<t) mx=t,rt=x;
    for(int i:e[x]){
        if(i==y||((x==a&&i==b)||(x==b&&i==a)))
            continue;
        if(g[x][0]==i) h[i]=max(f[x][1]+1,h[x]+1);
        else h[i]=max(f[x][0]+1,h[x]+1);
        dfs2(i,x);
    }
}
void dfs3(int x,int y){
    int siz=e[x].size();
    dep[x]=0;
    for(int i:e[x]){
        if(((x==a&&i==b)||(x==b&&i==a))) siz--;
        if(i==y||((x==a&&i==b)||(x==b&&i==a)))
            continue;
        dfs3(i,x);
        dep[x]=max(dep[x],dep[i]+1);
    }
    if(siz==1) dep[x]=0;
    c[dep[x]]++;
}
void solve(){
    for(int i=0;i<=n;i++)
        c[i]=0;
    dfs1(a,0);
    mx=-1,rt=0;
    dfs2(a,0),dfs3(rt,0);
    dfs1(b,0);
    mx=-1,rt=0;
    dfs2(b,0),dfs3(rt,0);
    for(int i=n-1;i>=0;i--)
        c[i]+=c[i+1];
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        if(c[mid]<=k)
            r=mid;
        else
            l=mid+1;
    }
    ans=min(ans,l);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int u,v;
    test=read(),T=read();
    while(T--){
        n=read(),k=read();
        for(int i=1;i<n;i++){
            u=read(),v=read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if(k==n)
            printf("0\n");
        else{
            ans=n;
            for(int i=1;i<=n;i++){
                for(int j:e[i]){
                    if(i<j){
                        a=i,b=j;
                        solve();
                    }
                }
            }
            printf("%d\n",ans);
        }
        for(int i=1;i<=n;i++)
            e[i].clear();
    }
    return 0;
}