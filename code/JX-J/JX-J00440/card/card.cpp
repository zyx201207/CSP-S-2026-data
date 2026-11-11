#include<bits/stdc++.h>
using namespace std;
const int M=3e5+10;
queue<int>q;
int vis[M],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(vis[a]>0){
            while(q.front()!=a&&!q.empty()){
                vis[q.front()]--;
                q.pop();
            }
        }else{
            q.push(a);
            vis[a]++;
        }
        for(int i=1;i<=m;i++){
            if(vis[i]>0){
                ans[i]++;
            }
        }
    }
     for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
     }
     return 0;
}
