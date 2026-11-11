#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+5],ans[m+5];
    bool vis[m+5];
    stack<int>s;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(s.top()!=a[j]){
                    vis[s.top()]=0;
                    s.pop();
                }
            }
            else{
                vis[a[j]]=1;
                s.push(a[j]);
            }
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
