#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[500005],a[500][1000],t[500][1000],w[500005],x,y;
int mp[1000][1000],dist[1000][1000],node[1000000],cnt,node2[1000000];
priority_queue<int,vector<int>,greater<int>> que;
void func(){
    int len=que.top();
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=m;j++){
            if(mp[node[i]][j]==len){
                node[++cnt]=j;
                node2[j]=1;
                dist[x][j]=dist[x][node[i]]+mp[node[i]][j];
                que.pop();
                if(j==y) return;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(mp[node[cnt]][i]&&!node2[i]) que.push(mp[node[cnt]][i]);
    }
    func();
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i]>>a[k[i]][1]>>t[k[i]][1];
        for(int j=2;j<=k[i];j++){
            cin>>a[k[i]][j]>>t[k[i]][j];
            mp[a[k[i]][j-1]][a[k[i]][j]]=t[k[i]][j]+t[k[i]][j-1];
            mp[a[k[i]][j]][a[k[i]][j-1]]=t[k[i]][j]+t[k[i]][j-1];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;

        dist[x][x]=0;
        for(int j=1;j<=m;j++){
            if(mp[x][j]) que.push(mp[x][j]);
            else break;
        }
        node[++cnt]=x;
        node2[x]=1;
        func();
        cout<<dist[x][y]+w[x]+w[y]<<endl;
        while(!que.empty()){
            que.pop();
        }
        cnt=0;
    }
    return 0;
}
