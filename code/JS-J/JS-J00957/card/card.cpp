#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>vis(m+1,0);
    vector<int>ans(m+1,0);
    deque<int>q;
    for(int t=1;t<=n;t++){
        for(int i=t;i<=n;i++){
            if(vis[a[i]]==1){
                int flag=0,l=q.size();
                for(int j=1;j<=l;j++){
                    int now=q.front();
                    q.pop_front();
                    vis[now]=0;
                    if(now==a[i])flag=1;
                    if(flag==0){
                        q.push_back(now);
                        vis[now]=1;
                    }
                }
                q.push_back(a[i]);
                vis[a[i]]=1;
            }else{
                q.push_back(a[i]);
                vis[a[i]]=1;
            }
        }
        while(!q.empty()){
            int now=q.front();
            ans[now]++;
            vis[now]=0;
            q.pop_front();
        }
    }

    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
