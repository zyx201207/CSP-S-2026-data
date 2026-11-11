#include<bits/stdc++.h>
using namespace std;
queue<int> q;
bool vis[500005];
int cnt[500005];
int a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==1){
                while(!q.empty()){
                    vis[q.front()]=0;
                    q.pop();
                }
            }
            q.push(a[j]);
            vis[a[j]]=1;
        }
        while(!q.empty()){
            cnt[q.front()]++;
            vis[q.front()]=0;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}

