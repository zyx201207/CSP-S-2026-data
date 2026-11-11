#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
const int N=100;
vector<int>a[N];
bool used[N];
bool edge[N][N];
int fa[N];
int find(int x) {
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void Union(int x,int y) {
    int tx=find(x),ty=find(y);
}
void dfs(int x,int lst) {
    if(x==k+1) {
        for(int i=1;i<=n;i++) {
            fa[i]=i;
        }
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                if(used[i]&&used[j]) Union(i,j);
            }
        }
        return ;
    }
    for(int i=lst+1;i<=n;i++) {
        used[i]=true;
        dfs(x+1,i);
        used[i]=false;
    }
}

int main() {
    cin>>c>>t;
    while(t--) {
        cin>>n>>k;
        for(int i=1;i<n;i++) {
            int u,v;cin>>u>>v;
            edge[u][v]=true;
            edge[v][u]=true;
        }
        dfs(1,0);
    }
    return 0;
}
/*



*/
