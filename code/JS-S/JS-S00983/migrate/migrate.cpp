#include<bits/stdc++.h>
using namespace std;
const int MN=5005;
int c,T;
int n,d;
int a[MN];
vector<int> g[MN];
int cnt,ans;


int bfs(int s,int t){
    int sum=0;
    int cnt=0;
    queue<pair<int,int> > q;
    q.push({s,0});
    while(!q.empty()){
        auto u=q.front().first;
        auto w=q.front().second;
        q.pop();
        for(auto v:g[u]){
            if(v==t){
                if(cnt==0){
                    sum=w+1;
                    cnt++;
                }else{
                    if(w+1==sum){
                        cnt++;
                    }
                }
                continue;
            }
            q.push({v,w+1});
        }
    }
    return cnt;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        ans=0;
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    g[i].push_back(j);
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int cnt=bfs(i,j);
                if(cnt==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
