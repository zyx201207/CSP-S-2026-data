
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long t1[N],dist[N];
vector<pair<int,int>> arr[N];
int bfs(int x,int y){
    queue<int>q;
    q.push(x);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(auto i:arr[t]){
            if(dist[t]+i.second<dist[i.first]){
                dist[i.first]=dist[t]+i.second;
                q.push(i.first);
            }
        }
    }
    return dist[y];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>t1[i];
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int x,y;
            cin>>x>>y;
            arr[x].push_back({j,y});
            arr[j].push_back({x,y});
        }
    }
    while(q--){
        memset(dist,0x3f,sizeof dist);
        int x,y;
        cin>>x>>y;
        dist[x]=0;
        int ans=bfs(x,y);
        ans+=t1[x]+t1[y];
        cout<<ans<<endl;
    }
    return 0;
}
