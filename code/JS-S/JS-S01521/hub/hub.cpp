#include <bits/stdc++.h>
using namespace std;
const int N=35;
int c,t,n,m,ans;
int b[N],cnt[N];
bool check[N],vis[N];
vector<int> v[N];
void count(int x){
    if(check[x])return ;
    for(auto k:v[x]){
        count(k);
        cnt[x]=min(cnt[x],cnt[k]+1);
    }
}
void dfs(int x,int dep){
    if(dep>m){
        for(int i=1;i<=n;i++){
            if(check[i]){
                cnt[i]=0;
            }
            else{
                cnt[i]=1e9;
            }
        }
        int num=0;
        for(int i=1;i<=n;i++){
            if(!check[i]){
                count(i);
            }
            num=max(num,cnt[i]);
        }
        ans=min(ans,num);
        return ;
    }
    for(int i=x+1;i<=n;i++){
        b[dep]=i;
        check[i]=true;
        dfs(i,dep+1);
        check[i]=false;
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        ans=1e9;
        for(int i=1;i<=n-1;i++){
            int x,y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(0,1);
        cout<<ans<<"\n";
    }
    return 0;
}
