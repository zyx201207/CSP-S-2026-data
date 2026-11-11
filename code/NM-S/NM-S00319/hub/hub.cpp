#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,k,ans,d[N][N],C;
bool f[N],b[N];
vector<int>a[N];
queue<int>q;
void init(int s){
    q.push(s);
    for(int i=1;i<=n;i++) f[i]=1;
    f[s]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto y:a[x]){
            if(!f[y]) continue;
            f[y]=0;
            d[s][y]=d[s][x]+1;
            q.push(y);
        }
    }
}
void dfs(int x){
    b[x]=0;
    for(auto y:a[x]){
        if(!b[y]) continue;
        dfs(y);
    }
}
void check(int x,int c){
    if(x>n){
        if(c!=k) return ;
        int cnt=0,les=0;
        for(int i=1;i<=n;i++)
            if(b[i]){
                dfs(i);
                ++cnt;
            }
        for(int i=1;i<=n;i++) b[i]=f[i];
        if(cnt<=2){
            for(int i=1;i<=n;i++){
                if(f[i]) continue;
                int mn=1e9;
                for(int j=1;j<=n;j++)
                    if(f[j]) mn=min(mn,d[i][j]);
                les=max(les,mn);
            }
            ans=min(ans,les);
        }
        return ;
    }
    if(c<k){
        f[x]=b[x]=1;
        check(x+1,c+1);
    }
    if(n-x+c>=k){
        f[x]=b[x]=0;
        check(x+1,c);
    }
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) d[i][j]=0;
        a[i].clear();
    }
    ans=1e9;
    for(int i=1,x,y;i<n;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=n;i++) init(i);
    check(1,0);
    cout<<ans<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int _;
    cin>>C>>_;
    while(_--) solve();
    return 0;
}
