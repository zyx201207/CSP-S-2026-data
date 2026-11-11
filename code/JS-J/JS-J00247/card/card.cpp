#include <bits/stdc++.h>
#define N 500100
#define M 300100
using namespace std;
int f[N],ans[M];
bool vis[M];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[f[j]]){
                while(s.top()!=f[j]){
                    vis[s.top()]=0;
                    s.pop();
                }
                s.pop();
            }
            vis[f[j]]=1;
            s.push(f[j]);
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
        for(int i=1;i<=m;i++){
            vis[i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
