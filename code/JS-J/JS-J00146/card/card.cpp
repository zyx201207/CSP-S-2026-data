#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int a[500005];
bool vis[300005];
int tj[300005];

signed main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int>q;
        for(int j=i;j<=n;j++){
            if(!vis[a[i]]){
                vis[a[i]]=true;
                q.push(a[j]);
            }else{
                while(q.top()!=a[i]){
                    q.pop();
                }
                q.pop();
                q.push(a[i]);
            }
        }
        while(!q.empty()){
            tj[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<tj[i]<<' ';
    }
    return 0;
}
