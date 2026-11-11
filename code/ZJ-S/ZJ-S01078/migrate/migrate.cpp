#include<bits/stdc++.h>
using namespace std;
#define getchar getchar_unlocked
typedef long long ll;
const int maxn=2e6+5;
int testid,T,n,arv[maxn];ll lim,x[maxn];bool used[maxn][7];int f[maxn][7];
int dfs1(int u);int dfs2(int u);int dfs3(int u);int dfs4(int u);int dfs5(int u);int dfs6(int u);
inline int calc(int p){
    if(arv[p]<=p)return 0;
    if(arv[p-1]<=p)return dfs1(p);
    if(arv[p-2]<=p){
        if(arv[p-1]==arv[p])return arv[p]-p+dfs2(p);
        return arv[p-1]-p+dfs4(p-1);
    }
    if(arv[p-2]==arv[p])return 0;
    if(arv[p-1]==arv[p])return arv[p]-arv[p-2]+dfs3(p-2);
    if(arv[p-2]==arv[p-1])return dfs5(p-1);
    return arv[p-1]-arv[p-2]+dfs6(p-2);
}
int dfs1(int u){
    if(used[u][1])return f[u][1];used[u][1]=1;
    int&res=f[u][1];if(arv[u]==u)res=0;
    else if(arv[u]==u+1)res=dfs1(u+1);
    else if(arv[u]==u+2){
        if(arv[u+2]<=u+2)res=0;
        else if(arv[u+1]==arv[u+2])res=arv[u+2]-(u+2)+dfs2(u+2);
        else if(arv[u+1]<=u+2)res=dfs1(u+2);
        else res=arv[u+1]-(u+2)+dfs4(u+1);
    }else res=calc(arv[u]);
    return res;
}
int dfs2(int u){
    if(used[u][2])return f[u][2];used[u][2]=1;
    int&res=f[u][2];if(arv[u]==u)res=0;
    else if(arv[u]==u+1)res=arv[u+1]-(u+1)+dfs2(u+1);
    else{
        int p=arv[u];
        if(arv[p]<=p)res=0;
        else if(arv[p]==arv[p-1])res=0;
        else if(arv[p-1]<=p)res=arv[p]-p+dfs2(p);
        else res=arv[p]-arv[p-1]+dfs3(p-1);
    }return
     res;
}
int dfs3(int u){
    if(used[u][3])return f[u][3];used[u][3]=1;
    int&res=f[u][3],q=arv[u+1];assert(arv[u]>u+1&&arv[u+1]>arv[u]);
    if(arv[q-1]>=arv[q])res=0;
    else if(arv[q-1]<=q)res=arv[q]-q+dfs2(q);
    else res=arv[q]-arv[q-1]+dfs3(q-1);
    return res;
}
int dfs4(int u){
    if(used[u][4])return f[u][4];used[u][4]=1;
    int&res=f[u][4],p=arv[u],q=arv[u+1];
    if(!(arv[u]>u+1&&arv[u+1]>arv[u]))assert(0);
    if(arv[p]>=arv[q])res=0;
    else if(p+1==q){
        if(arv[p]<=q)res=dfs1(q);
        else res=dfs5(p);
    }else res=calc(q);
    return res;
}
int dfs5(int u){
    if(used[u][5])return f[u][5];used[u][5]=1;
    int&res=f[u][5],p=arv[u],q=arv[u+1];
    if(!(arv[u]>u+1&&arv[u+1]>arv[u]))
        assert(0);
    if(arv[p]>=arv[q])res=0;
    else if(p+1==q){
        if(arv[p]<=q)res=dfs1(q);
        else res=dfs5(p);
    }
    else res=calc(q);
    return res;
}
int dfs6(int u){
    if(used[u][6])return f[u][6];used[u][6]=1;
    int&res=f[u][6],p=arv[u],q=arv[u+1],r=arv[u+2];
    assert(p>u+2&&q>p&&r>q);
    if(q+1==r){
        p=q-1;if(arv[p]==arv[p+2])res=0;
        else if(arv[p+1]==arv[p+2])res=0;
        else if(arv[p+1]<=p+2)res=dfs1(p+2);
        else res=dfs5(p+1);
    }else res=calc(r);
    return res;
}
inline int read(){
    char c;int f=1;for(c=getchar();c<'0'||c>'9';c=getchar())c=='-'&&(f=-1,0);
    int res=0;for(;c>='0'&&c<='9';c=getchar())
        res=(res<<1)+(res<<3)+(c^48);
    return res*f;
}
inline ll lread(){
    char c;int f=1;for(c=getchar();c<'0'||c>'9';c=getchar())c=='-'&&(f=-1,0);
    ll res=0ll;for(;c>='0'&&c<='9';c=getchar())
        res=(res<<1)+(res<<3)+(c^48);
    return res*f;
}
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int main(){open(migrate);
    for(testid=read(),T=read();T--;){
        n=read(),lim=lread();
        for (int i=1;i<=n;i++){x[i]=lread();for(int j=1;j<=6;j++)used[i][j]=0;}
        for(int i=1,j=1;i<=n;i++){
            for(;j<n&&x[j+1]-x[i]<=lim;j++);
            arv[i]=j;//cerr<<arv[i]<<" \n"[i==n];
        }ll ans=0ll;for(int i=n;i;i--)ans+=dfs1(i);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
1 1
6 12
-10 -6 -2 2 6 10
*/