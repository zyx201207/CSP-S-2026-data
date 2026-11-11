#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
const int N=5005;
ll a[N];
ll n,m,ans;
ll dp[N],step[N];
bool vis[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                for(int k=i;k<=j;k++){
                    dp[k]=0;
                    vis[k]=false;
                    step[k]=0;
                }
                dp[i]=1;
                vis[i]=true;
                step[i]=0;
                queue<int> q;
                q.push(i);
                while(q.size()){
                    int x=q.front();
                    //cout<<x<<" "<<dp[x]<<endl;
                    q.pop();
                    for(int p=x+1;p<=j;p++){
                        if(a[p]-a[x]>m)break;
                        if(!vis[p]){
                            vis[p]=true;
                            dp[p]=dp[x];
                            step[p]=step[x]+1;
                            q.push(p);
                        }
                        else{
                            if(step[x]<step[p]){
                                dp[p]+=dp[x];
                            }
                        }
                    }
                }
                if(dp[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
