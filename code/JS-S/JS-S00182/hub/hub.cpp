#include<bits/stdc++.h>
using namespace std;
const int N=15;
int c,t;
int n,k;
vector<int> a[N];
bool vis[N];
void dfs(int x,int i){
    vis[x]=true;
    for(auto j:a[x]){
        if(!vis[j]&&(i&1<<(j-1))){
            dfs(j,i);
        }
    }
}
struct node{
    int x,dis;
};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) a[i].clear();
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        int cnt=1;
        for(int i=1;i<=n;i++)
            cnt*=2;
        int ans=-1;
        for(int i=0;i<cnt;i++){
            //cout<<i<<' ';
            int sum=0;
            for(int j=1;j<=n;j++){
                if(i&(1<<(j-1))){
                    sum++;
                }
            }
            if(sum!=k){
                //cout<<" k\n";
                continue;
            }
            sum=0;
            for(int j=1;j<=n;j++) vis[j]=false;
            for(int j=1;j<=n;j++){
                if(i&(1<<(j-1))){
                    if(!vis[j]){
                        //cout<<"dfs : "<<j<<'\n';
                        dfs(j,i);
                        sum++;
                    }
                }
            }
            if(sum>2){
                //cout<<"lian tong\n";
                continue;
            }
            sum=0;
            for(int j=1;j<=n;j++){
                queue<node> q;
                if(i&(1<<(j-1))) continue;
                q.push({j,0});
                for(int k=1;k<=n;k++) vis[k]=false;
                while(!q.empty()){
                    node tmp=q.front();q.pop();
                    int x=tmp.x,dis=tmp.dis;
                    if(vis[x]) continue;
                    if(i&(1<<(x-1))){
                        //cout<<"j : "<<j<<" "<<" dis : "<<dis<<'\n';
                        sum=max(sum,dis);
                        break;
                    }
                    for(auto k:a[x]){
                        q.push({k,dis+1});
                    }
                }
            }
            //cout<<"sum : "<<sum<<'\n';
            //if(sum==1) cout<<"4574985643759483567943875943793475983787\n";
            if(ans==-1) ans=sum;
            ans=min(sum,ans);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
