#include <bits/stdc++.h>
#define endl "\n"
#define con continue
#define ret return
#define pb push_back
#define claer clear
#define rp(i,a,b) for(int i=(a);i<=(b);i++)
#define pr(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
//#define int long long
#define N 500005
void out(){
    cout<<endl;
}
template<class X,class ...Y>
void out(X x,Y...y){
    cout<<x;
    if(sizeof...(y)>0) cout<<" ";
    out(y...);
}
int aaa[N];
struct node{
    int v,w;
};
vector <node> mp[N+505];
vector <node> mp2[N+505];
int w[N];
long long dis[505][505];
int gm,n,m,d,q;
int read(){
    int res=0;
    char c=getchar();
    for(;isdigit(c);c=getchar()){
        res=(res<<1)+(res<<3)+c-'0';
    }
    ret res;
}
void solve(){
    gm=read();
    n=read();
    m=read();
    d=read();
    q=read();
    int cnt=0;
    rp(i,1,m){
        aaa[i]=read();
    }
    memset(dis,0x3f,sizeof(dis));
    rp(i,1,n){
        dis[i][i]=0;
    }
    rp(i,m+1,m+n){
        int k;
        k=read();
        rp(j,1,k){
            int a,b;
            a=read();
            b=read();
            mp[i].pb({a,b});
            mp2[a].pb({i,b});
        }
    }
    for(int i=m+1;i<=m+n;i++){
        for(node T:mp[i]){
            int v=T.v,W=T.w;
            w[v]=W;
        }
        rp(j,i+1,m+n){
            for(node T:mp[j]){
                int v=T.v,W=T.w;
                if(w[v]) dis[i-m][j-m]=min(dis[i-m][j-m],0ll+w[v]+W);
            }
            dis[j-m][i-m]=dis[i-m][j-m];
        }
        for(node T:mp[i]){
            int v=T.v,W=T.w;
            w[v]=0;
        }
    }
    for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
            }
        }
    }
    while(q--){
        int x,y;
        x=read();
        y=read();
        long long ans=1e18;
        for(node T:mp2[x]){
            int u=T.v,W1=T.w;
            for(node S:mp2[y]){
                int v=S.v,W2=S.w;
                ans=min(ans,dis[u-m][v-m]+W1+W2);
            }
        }
        cout<<ans+aaa[x]+aaa[y]<<endl;
    }
}
signed main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    solve();
}
