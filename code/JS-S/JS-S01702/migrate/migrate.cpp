#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[2000010];
long long ans=0;
vector<long long> g[2000010];
long long cnt[2000010];
long long leng[2000010];
void bfs(int s){
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(leng[u]>=leng[v])continue;
            if(leng[v]==1e7)q.push(v);
            if(leng[v]==1e7||leng[u]<leng[v]-1){
                leng[v]=leng[u]+1;
                cnt[v]=1;
            }
            else{
                cnt[v]++;
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        for(int i=1;i<=n;i++){
            while(g[i].size())g[i].pop_back();
        }
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]>d)break;
                g[i].push_back(j);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                leng[j]=1e7;
                cnt[j]=0;
            }
            leng[i]=1;
            cnt[i]=1;
            bfs(i);
            for(int j=i;j<=n;j++){
                if(cnt[j]==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
