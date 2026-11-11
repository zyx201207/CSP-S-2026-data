#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
const int N = 5000+5;
int a[N];
int ans[N];
void cnt(int i){
    pair<int,int>vis[N];
    queue<int>q;
    for(;i<=n;i++){
        if(!vis[a[i]].first){
            q.push(a[i]);
            vis[a[i]].first=1;
            vis[a[i]].second=i;
        }else{
            for(int j=vis[a[i]].second;j<i;j++){
                q.pop();
            }
            q.push(a[i]);
            vis[a[i]].second=i;
        }
    }
    while(!q.empty()){
        ans[q.front()]++;
        q.pop();
    }
    return ;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cnt(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" " ;
    }
    return 0;
}
