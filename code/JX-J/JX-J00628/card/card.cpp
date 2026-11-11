#include<bits/stdc++.h>
using namespace std;
int a[300005],n,m,k,b[300005];
stack<int> q;
bool vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    for(int j=1;j<=n;j++){
        memset(vis,0,sizeof(vis));
        for(int i=j;i<=n;i++){
            if(!vis[b[i]]){
                q.push(b[i]);
                vis[b[i]]=1;
            }
            else{
                while(q.top()!=b[i]){
                    vis[q.top()]=0;
                    q.pop();
                }
            }
        }
        while(!q.empty()){
            a[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

