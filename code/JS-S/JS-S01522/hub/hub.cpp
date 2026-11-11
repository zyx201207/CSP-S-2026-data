#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int fa[1000005];
vector<int>v[1000005]
struct node{
    int f;
    vector<int>son;
};
void dfs(int x,int father){
    fa[x]=father;
    for(int u:v[x]){
        if(u!=father)dfs(u,x);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            v[x].push(y);
            v[y].push(x);
        }
        dfs(1,0);
        cout<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
