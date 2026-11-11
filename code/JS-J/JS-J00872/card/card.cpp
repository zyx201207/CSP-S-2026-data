#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
bool vis[300010];
stack<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[a[i]]=1;
    }
    for(int i=1;i<=m;i++){
        ans[i]--;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=m;i++){
            vis[i]=0;
        }
        for(int l=k;l<=n;l++){
            if(vis[a[l]]==0){
                q.push(a[l]);
                vis[a[l]]=1;
            }
            else{
                while(!q.empty()){
                    if(q.top()!=a[l]){
                        vis[q.top()]=0;
                        q.pop();
                    }
                    else{
                        break;
                    }
                }
            }
        }
        while(!q.empty()){
            ans[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        if(ans[i]>=0){
            cout<<ans[i]<<' ';
        }
    }
    return 0;
}
