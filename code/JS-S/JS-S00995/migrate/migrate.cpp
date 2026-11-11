#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
struct node{
    int xx,y,dt;
};
int c,t,x[N],n,d,cnt,dis,dep[N],ccnt[N];
bool vis[N];
vector<int>a[N];
void dfs(int xx,int y,int dt){
    if(xx==y){
        if(dt<dis){
            dis=dt;
            cnt=1;
        }else if(dt==dis){
            ++cnt;
        }
    }
    vis[xx]=true;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        if(abs(x[xx]-x[i])>d)continue;
        dfs(i,y,dt+1);
    }
    vis[xx]=false;
}
void bfs(int xx){
    queue<int>q;
    q.push(xx);
    dep[xx]=0;
    while(!q.empty()){
        auto u=q.front();q.pop();
        for(auto i:a[u]){
            //if(i==4)cout<<u<<" "<<dep[u]<<endl;
            if(dep[u]+1>dep[i])continue;
            else if(dep[u]+1==dep[i]){
                //q.push(i);
                ccnt[i]++;
                //if(i==3)cout<<u<<" "<<i<<endl;
            }else if(dep[u]+1<dep[i]){
                q.push(i);
                dep[i]=dep[u]+1;
                ccnt[i]=1;
                //if(i==3)cout<<u<<" "<<i<<endl;
            }
        }
    }
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dis=1e18+5,cnt=0LL;
            dfs(i,j,0LL);
            if(cnt==2LL)ans++;
        }
    }
    cout<<ans<<"\n";
}
void solve2(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        dep[i]=1e18+5;
        a[i].clear();
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(abs(x[i]-x[j])<=d){
                a[i].push_back(j);
                a[j].push_back(i);
            }else break;
        }
    }
    //for(auto i:a[1])cout<<i<<" ";
    //cout<<endl;
    int ans=0LL;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dep[j]=1e18+5;
            ccnt[j]=0LL;
        }
        bfs(i);
        //cout<<dep[4]<<"\n";
        for(int j=i+1;j<=n;j++){
            if(ccnt[j]==2LL){
                ans++;
                //cout<<i<<" "<<j<<" "<<dep[j]<<endl;
            }
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    //freopen("1.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        if(n<=9)solve();
        else solve2();
    }
}
