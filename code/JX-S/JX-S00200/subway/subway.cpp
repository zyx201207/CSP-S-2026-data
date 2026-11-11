#include<bits/stdc++.h>
using namespace std;
long long cgun,n,m,d,q,w[500005],a[500005],t[500005][505],ff[500005],k,x,y,s;
struct v{
    long long sta,xian;
};
vector<v>b[500005];
struct u{
    long long star,en;
}bj;
map< pair<long long,long long> ,long long>c;
void dfs(long long o,long long p,long long Line){
    if(ff[o]) return;
    if(o==y){
        s=min(s,w[y]+t[y][Line]+p);
        return;
    }
    ff[o]=1;
    for(v i:b[o]){
        if(i.xian==Line&&!ff[i.sta]) dfs(i.sta,p,Line);
        else if(!ff[i.sta]) dfs(i.sta,t[o][Line]+t[o][i.xian]+p,i.xian);
    }
    ff[o]=0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>cgun>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++) cin>>a[j]>>t[a[j]][i];
        for(int j=1;j<k;j++) b[a[j]].push_back({a[j+1],i}),b[a[j+1]].push_back({a[j],i});
    }
    while(q--){
        cin>>x>>y,s=999999999999999999,memset(ff,0,sizeof(ff));
        if(x==y){cout<<"0\n";continue;}
        if(c[{x,y}]||c[{y,x}]){cout<<c[{x,y}]<<endl;continue;}
        for(int i=1;i<=n;i++) if(t[x][i]) dfs(x,w[x]+t[x][i],i);
        cout<<s<<endl;
        c[{x,y}]=s,c[{y,x}]=s;
    }
    return 0;
}
