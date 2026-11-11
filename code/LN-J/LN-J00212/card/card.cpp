#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,m;
int ans[500005];
int vis[500005];
void f(int start){
    vector<int>arr;
    for(int i=start;i<=n;i++){
        int x=a[i];
        if(vis[x]==0){
            arr.push_back(x);
            vis[x]++;
        }else{
            int id=0;
            for(int j=arr.size()-1;j>=0;j--){
                id++;
                if(arr[j]==x){
                    break;
                }
            }
            for(int j=1;j<=id;j++){
                vis[arr[arr.size()-1]]--;
                arr.pop_back();
            }
            arr.push_back(x);
            vis[x]++;
        }
    }
    for(int j=0;j<arr.size();j++){
        ans[arr[j]]++;
    }
    return;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        f(i);
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
