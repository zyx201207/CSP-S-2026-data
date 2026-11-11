#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[405],g[405][405],routes[405];
struct Station{
    int g2b;
    int trans[205];
    stack<int> q;
}sta[405];
int bfs(int x,int y,int time){
    if(x==y){
        time+=sta[y].g2b;
        return time;
    }
    else{
        for(int i=1;i<=400;i++){
            if(g[x][i]==1){
                if(routes[i]=2){
                    for(int j=1;j<=routes[i];j++){
                        int tmp=sta[i].q.top();
                        sta[i].q.pop();
                        int tmp2=sta[i].q.top();
                        sta[i].q.pop();
                        bfs(i,y,time+sta[i].trans[tmp]+sta[i].trans[tmp2]);
                    }
                }
                else bfs(i,y,time);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>sta[i].g2b;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        int a[405],t[405];
        for(int j=1;j<=2*k[i];j++){
            cin>>a[i]>>t[i];
            routes[a[i]]++;
            sta[a[i]].trans[i]=t[i];
            sta[i].q.push(i);
            g[a[i]][a[i-1]]=1;
            g[a[i-1]][a[i]]=1;
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<bfs(x,y,sta[x].g2b);
    }
    return 0;
}