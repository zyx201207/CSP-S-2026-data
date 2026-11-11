#include<bits/stdc++.h>
using namespace std;
int n,m,a[300011],ans[300011],vis[300011];
stack <int> s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));

        for(int j=i;j<=n;j++){
            s.push(a[j]);
            vis[a[j]]++;
            if(vis[a[j]]){
                s.pop();
                while(s.top()!=a[j]&&s.empty()!=1){
                    vis[s.top()]--;
                    s.pop();

                }

                vis[a[j]]--;
            }
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
