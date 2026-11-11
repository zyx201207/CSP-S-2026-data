#include<bits/stdc++.h>

using namespace std;
int a[500005],res[500005],pre[500005],ans[300005],ceng[500005],t[300005],to[500005];
bool vis[500005];
struct node{
    int ind,fu;
};
queue<node> q;
vector<int> g[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        pre[i]=t[a[i]];
        t[a[i]]=i;
    }
    for(int i=1;i<=n;i++) to[i]=t[a[i]];
    //for(int i=1;i<=n;i++) cerr<<pre[i]<<" ";
    //cerr<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;){
            if(to[j]==j){
                res[j]++;
                j++;
            }
            else j=to[j];
        }
    }
    for(int i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],res[i]);
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
