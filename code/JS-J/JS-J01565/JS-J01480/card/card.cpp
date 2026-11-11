#include<bits/stdc++.h>
using namespace std;
int yuan[500005];
vector<int> a[300005];
int ans[300005];
int n,m;
void dfs(int pos){
    if(pos==n+1){
        return;
    }
    bool vis=0;
    for(int j=0;j<a[yuan[pos]].size();j++){
        if(a[yuan[pos]][j]>pos){
            dfs(a[yuan[pos]][j]);
            vis=1;
            break;
        }
    }
    if(vis==1){
        return ;
    }
    ans[yuan[pos]]++;
    dfs(pos+1);
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>yuan[i];
        a[yuan[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        dfs(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
