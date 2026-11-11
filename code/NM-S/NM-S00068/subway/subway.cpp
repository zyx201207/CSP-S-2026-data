#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=15;
const int M=15;
int c,n,m,d,q;
ll w[M],dist[N*M][N*M];
struct p{
    int  x;ll d;
};
vector<p>v[N*M];
struct s{
    int x;ll d;
    bool operator<(const s& b)const{
        return d>b.d;
    }
};

void dijkstra(int st){
    priority_queue<s>q;
    dist[st][st]=0;
    q.push({st,0});
    while(!q.empty()){
        s stt=q.top();q.pop();
        int x=stt.x;
        //cout<<x<<' ';
        ll d2=dist[st][x];
        if(stt.d>d2)continue;
        for(p ss:v[x]){
            int y=ss.x;
            ll d=ss.d;
            if(dist[st][y]>
            stt.d+d){
                dist[st][y]=stt.d+d;
                q.push({y,dist[st][y]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<N*M;i++){
        for(int j=1;j<N*M;j++){
            dist[i][j]=2e18;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        vector<int>a(k+1);
        vector<ll>t(k+1);
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<k;j++){
            v[(i-1)*m+a[j]].push_back(
            {(i-1)*m+a[j+1],0});
            v[(i-1)*m+a[j+1]].push_back(
            {(i-1)*m+a[j],0});
        }
        for(int j=1;j<=k;j++){
            v[(i-1)*m+a[j]].push_back(
            {n*m+a[j],t[j]});
            v[n*m+a[j]].push_back(
            {(i-1)*m+a[j],t[j]});
        }
    }
    //for(int i=1;i<=(n+1)*m;i++){
    //    cout<<i<<":\n";
     //   for(p s:v[i]){
     //       cout<<"     "<<s.x<<' '<<s.d<<"\n";
    //    }
    //}
    for(int i=1;i<=m;i++){
        dijkstra(n*m+i);
        //cout<<"\n";
    }
    //for(int i=1;i<=(n+1)*m;i++){
    //    for(int j=1;j<=(n+1)*m;j++){
    //        cout<<dist[i][j]<<" ";
    //    }
    //    cout<<"\n";
    //}
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+dist[n*m+x][n*m+y]<<"\n";
    }

    return 0;
}
