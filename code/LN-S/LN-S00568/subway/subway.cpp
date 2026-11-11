#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-48;ch=getchar();}
    return x*f;
}
const int N=5e5+10;
int c,n,m,d,q;
int w[N],t[510][N];//
int fa[N][21];
namespace a1{
    int w[1010];
    int t[510][1010];
    vector <int> a[510];
    void solve(){
        for(int i=1;i<=m;i++) w[i]=read();
        for(int i=1,tmp;i<=n;i++){
            int k=read();
            for(int j=0;j<k;j++){
                tmp=read();
                a[i].push_back(tmp);
                t[i][j]=read();
            }
        }
        for(int i=1,x,y;i<=q;i++){
            x=read(),y=read();

        }
    }
}
namespace a2{
    int w[1010];
    int t[510][1010],dp[1010][51][51];
    vector <int> a[510];
    vector <int> G[1010];
    int minn=INT_MAX;
    void dfs(int u,int fa,int cen,int sum,int en){
        if(u==en&&cen==0){
            if(sum<=minn) minn=sum;
            return;
        }
        for(int i=0;i<=n;i++){
            dfs(u,fa,i,sum+dp[u][cen][i],en);
        }
        for(int v:G[u]){
            if(v==fa) continue;
            dfs(v,u,cen,sum,en);
        }
    }
    void solve(){
        for(int i=1;i<=m;i++) w[i]=read();
        for(int i=1,tmp;i<=n;i++){
            int k=read();
            for(int j=0;j<k;j++){
                tmp=read();
                a[i].push_back(tmp);
                t[i][tmp]=read();
            }
            for(int j=1;j<a[i].size();j++){
                G[a[i][0]].push_back(a[i][j]);
            }
        }
        for(int i=1;i<=m;i++){
            for(int j:a[i]){
                dp[i][0][j]=dp[i][j][0]=w[i];
                for(int k:a[i]){
                    if(j==k) continue;
                    if(j>k) dp[i][j][k]=dp[i][k][j];
                    else{
                        dp[i][j][k]=t[j][i]+t[k][i];
                    }
                }
            }
        }
        for(int i=1,x,y;i<=q;i++){
            x=read(),y=read();
            minn=INT_MAX;
            dfs(x,0,0,0,y);
            cout<<minn<<'\n';
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    a2::solve();
    return 0;
}
