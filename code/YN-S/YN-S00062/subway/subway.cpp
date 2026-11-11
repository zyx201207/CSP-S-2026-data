#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define int long long
inline int read(){
    int x=0,f=1;
    char c;
    c=gc();
    while(c<'0'||'9'<c){
        if(c=='-')f=-f;
        if(c==EOF)return 0;
        c=gc();
    }
    if(c==EOF)return 0;
    while('0'<=c&&c<='9'){
        x=x*10+c-'0';
        c=gc();
    }
    return f*x;
}
inline void print(int x){
    if(x<0){
        pc('-');
        x=-x;
    }
    if(x>9)print(x/10);
    pc('0'+x%10);
}
const int N=5e5+5;
struct node{int v,t;};
vector<node> gst[N];
int c,n,m,d,q;
int w[N];
int dp[505][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            int x=read(),t=read();
            gst[x].push_back({i,t});
        }
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=m;i++){
        for(auto [u,ut]:gst[i]){
            for(auto [v,vt]:gst[i]){
                if(u==v)continue;
                int t=vt+ut;
                dp[u][v]=t;
            }
        }
    }
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int u=1;u<=n;u++)
            for(int v=1;v<=n;v++)
                dp[u][v]=min(dp[u][k]+dp[k][v],dp[u][v]);
    while(q--){
        int s=read(),e=read();
        int ans=1e18;
        for(auto [u,ut]:gst[s])
            for(auto [v,vt]:gst[e])
                ans=min(ans,dp[u][v]+w[s]+w[e]+vt+ut);
        print(ans);
        pc('\n');
    }
    return 0;
}
