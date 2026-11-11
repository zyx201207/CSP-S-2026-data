#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> e[N];
bool vis[N];
int dis[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;++i)e[i].clear();
        for(int i=1,a,b;i<n;++i){
            cin>>a>>b;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        int ans=1e9;
        for(int s=1;s<(1<<n);++s)if(__builtin_popcount(s)==k){
            int cnt=0;
            for(int j=0;j<n;++j){
                if(s>>j&1){
                    ++cnt;
                    for(int k:e[j+1])if(k<=j&&s>>k-1&1){
                        --cnt;
                    }
                }

            }
            if(cnt>2)continue;
            memset(vis,false,sizeof vis);
            vector<int> q;
            for(int i=0;i<n;++i)if(s>>i&1){
                    q.push_back(i+1);
                    vis[i+1]=true;
                    dis[i+1]=0;
            }
            for(int i=0;i<q.size();++i)
                for(int j:e[q[i]])if(!vis[j]){
                    dis[j]=dis[i]+1;
                    vis[j]=true;
                    q.push_back(j);
                }
            ans=min(ans,dis[q.back()]);
        }
        cout<<ans<<'\n';
    }
}
