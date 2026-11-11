#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define pii pair<int,int>
#define u_mp unordered_map
#define u_st unordered_set
#define prio_q priority_queue
#define ll long long
int c,t,n,d;
int a[100000];
vector<int>g[10000];
int ans,cnt;
int vis[10000];
void dfs(int st,int fin,int sum){
    if(st==fin){
        if(ans>sum){
            ans=sum;
            cnt=1;
        }else if(ans==sum){
            cnt++;
        }
        return;
    }
    if(sum>=ans){
        return;
    }
    for(auto i:g[st]){
        if(!vis[i]){
            vis[i]=1;
            dfs(i,fin,sum+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
        while(t--){
            for(int i=1;i<=n;i++){
                g[i].clear();
            }
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
                for(int j=1;j<i;j++){
                    if(abs(a[i]-a[j])<=d){
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                }
            }
            int sum=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    vis[i]=1;
                    ans=INT_MAX;
                    cnt=0;
                    dfs(i,j,0);
                    if(cnt==2){
                        sum++;
                    }
                }
                vis[i]=0;
            }
            cout<<sum<<endl;
        }
    
    return 0;
}