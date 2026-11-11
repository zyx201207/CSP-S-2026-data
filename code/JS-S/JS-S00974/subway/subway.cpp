#include<bits/stdc++.h>
using namespace std;
long long dis[501][501];
long long w[500005];
struct st{
    long long wh,shi;
};
vector<st> hav[500005];
long long read(){
    long long tool=0;
    while(1){
        char c=getchar();
        if(c=='\n'||c==' ') break;
        tool=tool*10+c-'0';
    }
    return tool;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    c=read(),n=read(),m=read(),d=read(),q=read();
    //cerr<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<"\n";
    //cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) w[i]=read();
    //cerr<<"\n";
    for(int i=1;i<=n;i++){
        int k;
        k=read();
        //cerr<<k<<" ";
        for(int j=1;j<=k;j++){
            long long t1,t2;
            t1=read(),t2=read();
            //cerr<<
            hav[t1].push_back({i,t2});
        }
    }
    //return 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=1000000000000000ll;
    for(int i=1;i<=m;i++){
        for(auto v:hav[i]){
            for(auto u:hav[i]){
                if(v.wh==u.wh) continue;
                dis[v.wh][u.wh]=min(dis[v.wh][u.wh],v.shi+u.shi);
                dis[u.wh][v.wh]=dis[v.wh][u.wh];
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j]=dis[i][k]+dis[k][j];
    int t1,t2;
    long long ans=1000000000000000ll,res;
    while(q--){
        ans=1000000000000000ll;
        t1=read(),t2=read();
        for(auto v:hav[t1])
        for(auto u:hav[t2]){
            res=v.shi+u.shi+dis[v.wh][u.wh];
            ans=min(ans,res);
        }
        ans+=w[t1]+w[t2];
        cout<<ans<<"\n";
    }
    return 0;
}
