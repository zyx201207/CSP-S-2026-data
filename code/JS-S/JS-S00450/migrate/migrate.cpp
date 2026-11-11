#include <bits/stdc++.h>
using namespace std;
const int maxn=2e2+5;
int c,t;
vector<int> a[maxn];
int dis[maxn][maxn];
int cnt[maxn][maxn];
void bfs(int s){
    bool vis[maxn];
    memset(vis,0,sizeof(vis));
    vis[s]=1;
    queue<pair<int,int>> q;
    dis[s][s]=0;
    q.push(make_pair(s,0));
    while(!q.empty()){
        auto temp=q.front();
        int level=temp.second;
        int node=temp.first;
        for(auto k:a[node]){
            if(vis[k]){
                if(dis[s][k]==level+1){
                    cnt[s][k]++;
                    q.push(make_pair(k,level+1));
                }
            }else{
                cnt[s][k]=1;
                dis[s][k]=level;
                q.push(make_pair(k,level+1));
            }
        }
    }
}
int main(){
    cin >> c>>t;
    while(t--){
        int n,d;
        cin >> n >> d;
        for(int i=0;i<n;i++){
            a[i].clear();
        }
        int x[maxn];
        for(int i=0;i<n;i++){
            cin >> x[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(j>i+d){break;}
                if(abs(x[i]-x[j])<=d){
                    a[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            bfs(i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << dis[i][j] << ' ';
            }
            cout << endl;
        }
    }
}
