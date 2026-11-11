#include<bits/stdc++.h>
using namespace std;queue<int>q;
long long c,ans,x,y, k,n, m, d, q1,w[100000],dp[676],t[600][600],a[666][5901];
vector<int>zhantai[555];
bool flag[555];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q1;
for(int i=1;i<=m;i++)cin>>w[i];
for(int i=1;i<=n;i++){
    cin>>k;
    for(int j=1;j<=k;j++){
        cin>>a[i][j]>>t[i][j];
        zhantai[a[i][j]].push_back(i);
    }
}
while(q1--){
    ans=0;
    cin>>x>>y;
    ans=ans+w[x]+w[y];
    while(!q.empty())q.pop();
    q.push(x);
    for(int i=1;i<=m;i++)dp[i]=1e9,flag[i]=0;
    flag[x]=1;
    dp[x]=0;
    while(!q.empty()){
            int op=0;
        int u=q.front();
        q.pop();
        //cout<<u<<" ";
        for(int i=0;i<(int)zhantai[u].size();i++){
            int xianlu=zhantai[u][i];
            for(int j=1;a[xianlu][j]!=0;++j){
                dp[a[xianlu][j]]=min(dp[a[xianlu][j]],dp[u]+t[u][u]+t[u][a[xianlu][j]]);
            if(a[xianlu][j]==y){
                cout<<ans+dp[a[xianlu][j]]<<"\n";
    op++;
                break;
            }    if(!flag[a[xianlu][j]]){
                    flag[a[xianlu][j]]=1;
                    q.push(a[xianlu][j]);
                }
            }if(op)break;
        }

    }
}
return 0;
}
