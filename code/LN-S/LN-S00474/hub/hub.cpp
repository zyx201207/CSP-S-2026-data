#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
#define rep(i,t1,t2,t3) for(decltype((t1)+(t2)+(t3)) i=(t1);i<=(t2);i+=(t3))
#define per(i,t1,t2,t3) for(decltype((t1)+(t2)+(t3)) i=(t1);i>=(t2);i-=(t3))
#define pb push_back
void work1(){
    //testcase 1~3 15pts
    int n,k;cin>>n>>k;
    vector<vector<int>> edges(n+1);
    rep(i,1,n-1,1){
        int u,v;cin>>u>>v;
        edges[u].pb(v),edges[v].pb(u);
    }
    vector<int> choose(n+1);
    auto judge=[&]()->bool{
        //rep(i,1,n,1) cout<<choose[i]<<' ';
        //cout<<'\n';
        vector<int> UP(n+1);
        function<void(int,int,int)> dfs1=[&](int x,int up,int fa){
            UP[x]=up;
            for(auto y:edges[x]) if(y!=fa){
                int newup=(!choose[y]?0:(up==0?y:up));
                dfs1(y,newup,x);
            }
        };
        dfs1(1,choose[1],-1);
        set<int> st;
        rep(i,1,n,1) if(choose[i]) st.insert(UP[i]);
        return int(st.size())<=2;
    };
    int ans=n+1;
    function<void(int,int)> dfs=[&](int pre,int rem){
        if(!rem){
            if(!judge()) return;
            queue<int> q;
            vector<int> dis(n+1,-1);
            rep(i,1,n,1) if(choose[i]) dis[i]=0,q.push(i);
            while(!q.empty()){
                int U=q.front();q.pop();
                for(auto V:edges[U]) if(dis[V]==-1){
                    dis[V]=dis[U]+1,q.push(V);
                }
            }
            ans=min(ans,*max_element(dis.begin()+1,dis.end()));
            return;
        }
        rep(i,pre+1,n,1){
            if(n-i<rem-1) break;
            choose[i]=1;
            dfs(i,rem-1);
            choose[i]=0;
        }
    };
    dfs(0,k);
    cout<<ans<<'\n';
}
void work2(){
    //testcase 7 5pts
    int n,k;cin>>n>>k;
    vector<vector<int>> edges(n+1);
    rep(i,1,n-1,1){
        int u,v;cin>>u>>v;
        edges[u].pb(v),edges[v].pb(u);
    }
    vector<vector<int>> dis(n+1,vector<int>(n+1,-1));
    rep(i,1,n,1){
        queue<int> q;
        q.push(i),dis[i][i]=0;
        while(!q.empty()){
            int x=q.front();q.pop();
            for(auto y:edges[x]) if(dis[i][y]==-1){
                dis[i][y]=dis[i][x]+1,q.push(y);
            }
        }
    }
    int ans=n+1;
    rep(i,1,n,1) rep(j,i+1,n,1){
        int cur=0;
        rep(k,1,n,1) cur=max(cur,min(dis[i][k],dis[j][k]));
        //cout<<i<<' '<<j<<':'<<cur<<'\n';
        ans=min(ans,cur);
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,T;cin>>c>>T;
    if(c!=7 && c!=11 && c!=12){
        while(T--) work1();
    }else{
        while(T--) work2();
    }
    return 0;
}
