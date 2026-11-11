#include <bits/stdc++.h>
using namespace std;
long long maze[10000005],used[10000005],dp[10000005],used2[10000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>maze[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[j]=0;
        }
        for(int j=1;j<=n;j++){
            used2[j]=0;
        }
        for(int j=i;j<=n;j++){
            dp[maze[j]]++;
            if(dp[maze[j]]>1){
                for(int x=j-1;x>=1;x--){
                    if(used2[x]==0){
                        dp[maze[x]]--;
                        used2[x]=1;
                    }
                    if(maze[j]==maze[x]&&used2[x]==0)
                    {
                        break;
                    }

                }
            }
        }
        for(int j=i;j<=n;j++){
            if(used2[j]==0){
                used[maze[j]]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<used[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<used[i]<<" ";
    }
}
