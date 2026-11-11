#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=100005;
int n,k,ans=0,fa[N],dep[N],mxd[N],mx[N];
vector<int>e[N];
bool a[N];

int dis(int x,int y){
    int cnt=0;
    if(dep[x]<dep[y])swap(x,y);
    while(dep[fa[x]]>=dep[y])x=fa[x],cnt++;
    if(x==y)return cnt;
    while(fa[x]!=fa[y])x=fa[x],y=fa[y],cnt+=2;
    return cnt+2;
}

int check(){
    vector<int>vec;
    for(int i=1;i<=n;i++)
        if(a[i])vec.push_back(i);
    int ua=0;
    for(int i=1;i<=n;i++){
        if(a[i])continue;
        int mn=114514;
        for(int j:vec)
            mn=min(mn,dis(i,j));
        ua=max(ua,mn);
    }
    return ua;
}

void dfsss(int u,int cur,int cnt){
    if(u==n+1){
        if(cur==k)ans=min(ans,check());
        return;
    }
    if(n-u+1+cur<k)return;
    if(cur+1<=k){
        bool isu=1;
        for(int v:e[u])
            if(a[v])isu=0;
        if(cnt==2&&!isu){
            a[u]=1;
            dfsss(u+1,cur+1,2);
        }else if(cnt<2){
            a[u]=1;
            dfsss(u+1,cur+1,cnt+isu);
        }
    }
    a[u]=0;
    dfsss(u+1,cur,cnt);
}

void getsss(int u,int f){
    fa[u]=f;dep[u]=dep[f]+1;
    for(int v:e[u]){
        if(v==f)continue;
        getsss(v,u);
    }
}

void solve(){
    cin>>n>>k;ans=1e18;
    for(int i=1;i<=n;i++)e[i].clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    getsss(1,0);
    dfsss(1,0,0);cout<<ans<<'\n';
}

void solve3(){
    cin>>n>>k;
    for(int i=1,u,v;i<n;i++)cin>>u>>v;
    if(n==k){cout<<"0\n";return;}
    int m=(n-1)/2,blank=m-k,ans=n;
    for(int b=0;b<=blank;b++){
        int r=(blank-b)/2,tmp=0;
        if(r%2==1)tmp=r+2;
        else tmp=r+1;
        if(b){
            int cb=b;
            if(b%2==0)cb=b-1;
            tmp=max(tmp,(cb+1)/2+1);
        }
        ans=min(ans,tmp);
    }
    cout<<ans<<'\n';
}

void dfs2(int u,int fa){
    mx[u]=1;dep[u]=dep[fa]+1;
    mxd[u]=dep[u];
    int mxl=0,sel=0;
    for(int v:e[u]){
        if(v==fa)continue;
        dfs2(v,u);
        mxd[u]=max(mxd[u],mxd[v]);
        mx[u]=max(mx[u],mx[v]);
        if(mxd[v]-dep[u]>mxl)sel=mxl,mxl=mxd[v]-dep[u];
        else if(mxd[v]-dep[u]>sel)sel=mxd[v]-dep[u];
    }
    mxd[u]=max(mxd[u],dep[u]);
    mx[u]=max(mx[u],sel+mxl+1);
}

void solve2(){
    cin>>n>>k;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ans=1e18;dep[0]=-1;
    for(int s=1;s<=n;s++){
        dfs2(s,0);
        int tt=0,mxx=0,mxc=0,mxv=0,se=0;
        for(int v:e[s]){
            int uo=mxd[v];
            if(mxd[v]>mxx)mxx=mxd[v],mxv=v,mxc=1;
            else if(mxd[v]==mxx)mxc++;
            else if(mxd[v]>se)se=mxd[v];
        }
        if(mxc>1)ans=min(ans,mxx);
        else ans=min(ans,max(se,mx[mxv]/2));
    }
    cout<<ans<<'\n';
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int c,t;cin>>c>>t;
    if(c<=3)while(t--)solve();
    else if(c==7)while(t--) solve2();
    else if(13<=c&&c<=14)while(t--)solve3();
}
/*
7 1
8 2
1 2
2 3
3 4
4 5
3 6
6 7
6 8
*/
