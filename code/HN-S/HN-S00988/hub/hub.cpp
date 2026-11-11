#include <bits/stdc++.h>
#define lint __int128
#define int long long
#define Il inline
#define fi first
#define se second
#define vec vector
#define pb push_back
#define IT ::iterator
#define p_q priority_queue

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef double db;
const int N=1e6,Inf=1e9;
const db eps=1e-9;

// bool P1;

int testcase,T,n,m,df[N+5],dfn=0,vt[N+5],de[N+5],nd[N+5],lg[N+5],bd[N+5];
int f[N+5][2][3];
int st[N+5][25];
bool vis[N+5],kp[N+5];
vec<int>v[N+5];

Il bool cmp1(int x,int y){
    return de[x]>de[y];
}

Il int Min(int x,int y){
    return de[x]<de[y]?x:y;
}

Il void dfs1(int p,int fr){
    de[p]=de[vt[p]=fr]+1,df[p]=++dfn;
    for(int i:v[p]){
        if(i==fr)continue;
        dfs1(i,p);
    }
    return;
}

Il int lca(int x,int y){
    if(df[x]>df[y]){
        swap(x,y);
    }
    if(x==y)return x;
    x=df[x]+1,y=df[y];
    int t=lg[y-x+1];
    return vt[Min(st[x][t],st[y-(1<<t)+1][t])];
}

Il int dis(int x,int y){
    return de[x]+de[y]-(de[lca(x,y)]<<1);
}

Il void dfs2(int p){
    f[p][0][0]=(kp[p]?Inf:0),f[p][1][0]=f[p][1][2]=f[p][0][1]=f[p][0][2]=Inf,f[p][1][1]=1;
    for(int i:v[p]){
        if(i==vt[p])continue;
        dfs2(i);
        f[p][0][2]=min(f[p][0][0]+min(f[i][0][2],f[i][1][2]),min(f[p][0][2]+f[i][0][0],f[p][0][1]+min(f[i][0][1],f[i][1][1])));
        f[p][0][1]=min(f[p][0][1]+f[i][0][0],f[p][0][0]+min(f[i][0][1],f[i][1][1]));
        f[p][0][0]+=f[i][0][0];
        f[p][1][2]=min(f[p][1][2]+min(f[i][0][0],f[i][1][1]),f[p][1][1]+min(f[i][1][2],f[i][0][1]));
        f[p][1][1]+=min(f[i][1][1],f[i][0][0]);
    }
    return;
}

Il void Init1(){
    for(int i=1;i<=n;i++){
        v[i].resize(0),df[i]=bd[i]=0;
    }
    dfn=0;
    return;
}

Il void Init2(){
    for(int i=1;i<=n;i++){
        vis[i]=kp[i]=0;
    }
    return;
}

Il bool check(int x){
    for(int _=1;_<=n;_++){
        int po=nd[_],p=po;
        if(vis[po])continue;
        for(int j=1;vt[p]&&j<=x;j++){
            p=vt[p];
        }
        kp[p]=1;
        for(int i=1;i<=n;i++){
            vis[i]|=(dis(i,p)<=x);
        }
    }
    dfs2(1);int t=Inf;
    for(int i=1;i<=n;i++){
        // cout<<i<<": ";
        // for(int j=0;j<2;j++){
        //     for(int k=0;k<3;k++){
        //         cout<<f[i][j][k]<<' ';
        //     }
        // }
        // cout<<'\n';
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            t=min(t,f[1][i][j]);
        }
    }
    Init2();
    return t<=m;
}

Il void yuanshenqidong(){
    cin>>n>>m;
    for(int i=1,x,y;i<n;i++){
        cin>>x>>y,v[x].pb(y),v[y].pb(x);
    }
    dfs1(1,0);
    for(int i=1;i<=n;i++){
        nd[i]=i,st[df[i]][0]=i;
    }
    sort(nd+1,nd+n+1,cmp1);
    for(int j=1;j<=lg[n];j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=Min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dis(i,j)<<' ';
    //     }
    //     cout<<'\n';
    // }
    int l=n/m-1,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<r+1<<'\n';
    return;
}

// bool P2;

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // cout<<abs((&P1)-(&P2))/1024/1024;return 0;
    for(int i=2;i<=N;i++){
        lg[i]=lg[i>>1]+1;
    }
    cin>>testcase>>T;
    while(T--){
        yuanshenqidong(),Init1();
    }
    return 0;
}
/*
整理一下
首先你二分答案 x
然后选择是形如
对所有未覆盖的点找到最深的那个，让它往上跳至多 x 步的祖先记为 p
然后删掉 p 的 x 邻域
这样你得到了 K 个点，问能不能用 m-K 个点把它们连成至多两个连通块
f[i][0/1][j] 子树 i，i 是否选，子树内有 j=0/1/2 个连通块所需最少点
check 一下正确性先
如果对的话这个 check 可以通过一些诡异方式做到线性应该是可以的
假掉了。。。为啥啊
哦好像真的假了。。。
完蛋了
*/