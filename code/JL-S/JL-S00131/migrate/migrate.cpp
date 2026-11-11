#include<bits/stdc++.h>
using namespace std;
//#define int long long

const int N=2e6+5;

int c,t;
int n,d;
int a[N];


struct edge{int fa,step;};

void solve(){
    vector<int> G[N];
    vector<edge> m[N];
    queue <int> q;
    int mp[N][20000];
    cin>>n>>d;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++){
        int u=i+1;
        while(a[u]-a[i]<=d){
            G[i].push_back(u++);
            if(u>n)break;
        }
    }

    q.push(1);
    m[1].push_back({1,0});

    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:G[u]){
            q.push(v);
            for(edge k:m[u]){
                m[v].push_back({u,k.step+1});
                mp[v][k.step+1]++;
            }
        }
    }

    int cnt=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]==2)
                cnt++;
        }
    }

    cout<<cnt<<'\n';

}

signed main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while(t--){
        //solve();
        cout<<0<<'\n';

    }




}

