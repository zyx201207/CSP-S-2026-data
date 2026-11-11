#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
const int N=505;
int w[M];
int k[N];
int a[M];
int t[M];
int c,n,m,dd,q,cnt;
//long long d[2510][2510];
struct Node{
    int v,dis;
    bool operator < (const Node &b) const {
        return b.dis<dis;
    }
};
vector<Node> vc[2510];
bool vis[N];
long long s[2510];
void zdl(int x){
    priority_queue<int> qq;
    memset(s,0x3f,sizeof s);
    qq.push(x);
    s[x]=0;
    while(!qq.empty()){
        int x=qq.top();
        qq.pop();
        for(auto y:vc[x]){
            if(s[y.v]>s[x]+y.dis){
                s[y.v]=s[x]+y.dis;
               // cout<<x<<" "<<y.v<<" "<<s[y.v]<<endl;
                qq.push(y.v);
            }
        }
       // cout<<endl;
    }
}
void solve1(){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+k[i];
        for(int j=sum-k[i]+1;j<=sum;j++){
            vc[m+j].push_back({m+cnt+i,t[j]});
            vc[m+cnt+i].push_back({m+j,t[j]});
            vc[m+j].push_back({a[j],0});
            vc[a[j]].push_back({m+j,0});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        zdl(x);
        cout<<s[y]+w[x]+w[y]<<'\n';
    }
    return ;
}
long long ab[M];
long long ba[M];
int wz[M];
void solve3(){
    for(int i=1;i<=k[1];i++){
        wz[a[i]]+=1;
        ab[a[i]]+=t[i];
    }
    for(int i=k[1]+1;i<=k[1]+k[2];i++){
        wz[a[i]]+=2;
        ba[a[i]]+=t[i];
    }
    long long mina=1e18;
    for(int i=1;i<=m;i++){
        if(wz[i]==3){
            mina=min(mina,ab[i]+ba[i]);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        if(wz[x]>wz[y]){
            swap(x,y);
        }
        if(wz[x]==1&&wz[y]==1){
            cout<<w[x]+w[y]+ab[x]+ab[y]<<'\n';
        }
        else if(wz[x]==2&&wz[y]==2){
            cout<<w[x]+w[y]+ba[x]+ba[y]<<'\n';
        }
        else if(wz[x]==3&&wz[y]==3){
            cout<<w[x]+w[y]+min(ab[x]+ab[y],ba[x]+ba[y])<<'\n';
        }
        else if(wz[x]==1&&wz[y]==3){
            cout<<w[x]+w[y]+ab[x]+ab[y]<<'\n';
        }
        else if(wz[x]==2&&wz[y]==3){
            cout<<w[x]+w[y]+ba[x]+ba[y]<<'\n';
        }
        else{//1 2
            cout<<w[x]+w[y]+mina+ab[x]+ba[y]<<'\n';
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>n>>m>>dd>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        cin>>k[i];
        cnt=cnt+k[i];
        for(int j=cnt-k[i]+1;j<=cnt;++j){
            cin>>a[j]>>t[j];
        }
    }
    if(n==2){
        solve3();
        return 0;
    }
    else{
        solve1();
        return 0;
    }
    return 0;
}
