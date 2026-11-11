#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+10;
int c,T;
int ans=0;
int vh[5010][5010],ls[5010][5010];
int n,d,x[N];
vector<int>g[N];
void bfs(int s){
    priority_queue<pair<int,int>>q;
    q.push({s,0});
    while(!q.empty()){
        int id=q.top().first,sm=q.top().second;
        q.pop();
        if(ls[s][id]==0){
            ls[s][id]=sm;
        }
        if(ls[s][id]==sm){
            vh[s][id]++;
            if(vh[s][id]==2){
                ans++;
            }else if(vh[s][id]>2){
                ans--;
            }
        }
        if(sm<=ls[s][id]&&vh[s][id]>=2){
            continue;
        }
        for(auto i:g[id]){
            q.push({i,sm+vh[s][id]} );
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;++i){
            cin>>x[i];
            for(int j=1;j<i;++j){
                if(x[i]-x[j]<=d){
                    g[j].push_back(i);
                }
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                vh[i][j]=ls[i][j]=0;
            }
            bfs(i);
        }
        for(int i=1;i<=n;++i){
            g[i].clear();
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}