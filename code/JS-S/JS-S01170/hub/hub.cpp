#include<bits/stdc++.h>
using namespace std;
int n,k,ans=2e9;
vector<int> g[55];
int check(int mask){
    vector<int> v[55];
    set<int> cur;
    queue<int> q;
    for(int i=0;i<n;i++){
        if((1<<i)&mask){
            cur.insert(i);
            cout<<i<<" ";
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<g[i].size();j++){
            if(cur.find(g[i][j])!=cur.end()){
                v[i].push_back(g[i][j]);
                v[g[i][j]].push_back(i);
            }
        }
    }
    int cnt=1,cntt=0;
    while(cnt<=k){
        cntt++;
        q.push(*cur.begin());
        cur.erase(*cur.begin());
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto t:v[x]){
                if(cur.find(t)!=cur.end()){
                    q.push(t);
                    cur.erase(t);
                }
            }
        }
    }
    if(cntt!=2){
            cout<<"DIE"<<endl;
        return 2e9;
    }
    return 0;
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        g[i].clear();
    }
    int u,v;
    for(int i=0;i<(n-1);i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<(1<<n);i++){
        int st=i,cnt=0;
        while(st){
            cnt+=(st%2);
            st/=2;
        }
        if(cnt!=k) continue;
        ans=min(ans,check(i));
    }
}
signed main(){
    int c,t;
    cin>>c>>t;
    while(t>0){
        t--;
        solve();
    }
}
