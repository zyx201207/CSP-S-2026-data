#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<int>a(n+5);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c<=6){
            vector<vector<int>>edge(n+5);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(a[i]-a[j]<=d&&i!=j)edge[i].emplace_back(j);
                }   
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                vector<pair<int,int>>dis(n+5);
                queue<pair<int,int>>q;
                q.push({i,0});
                while(!q.empty()){
                    auto o=q.front();
                    q.pop();
                    int oa=o.first,ob=o.second;
                    if(dis[oa].second==ob){
                        dis[oa].first++;
                        for(int xx:edge[oa]){
                            q.push({xx,ob+1});
                        }
                    }
                    else if(dis[oa].first==0){
                        dis[oa].first++;
                        dis[oa].second=ob;
                        for(int xx:edge[oa]){
                            q.push({xx,ob+1});
                        }
                    }
                }
                for(auto z:dis){
                    if(z.first==2)ans++;
                }
            }
            cout<<ans<<'\n';
        }
        else if(c==11||c==12){
            cout<<n-d/(a[2]-a[1])*2
        }
    }
}