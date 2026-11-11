#include <bits/stdc++.h>
using namespace std;
int a[200005];
int t[200005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        queue<int> q;
        for(int j=i;j<=n;j++){
            q.push(a[j]);
            if(q.front()==a[j]&&q.size()>1){
                q.pop();
                while(q.front()!=a[j]){
                    q.pop();
                }
            }
        }
        bool vis[200005];
        memset(vis,false,sizeof(vis));
        while(!q.empty()){
            vis[q.front()]=true;
            q.pop();
        }
        for(int j=1;j<=m;j++){
            if(vis[j]){
                t[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<' ';
    }
    return 0;
}
