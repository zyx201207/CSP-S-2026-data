#include <bits/stdc++.h>
using namespace std;
struct line{
    int type,length,dest;
};
int exsta[700001];
vector<line> stapla[700001];
int c,n,m,d,q;
int bfs(int x,int y){
    pair<int,int> dis[700001];
    memset(dis,127,sizeof dis);
    dis[x]={0,0};
    queue<pair<int,int> > q;
    for(line u:stapla[x]){
        q.push({u.dest,u.type});
    }
    cerr<<"Start of search check\n";
    while(dis[y].first==0x7f7f7f7f){
        auto now=q.front();
        q.pop();
        if(now.first>m){
            for(line u:stapla[now.first]){
                if(dis[u.dest].first==0x7f7f7f7f||dis[u.dest].second!=u.type)q.push({u.dest,u.type});
                if(dis[u.dest].second!=u.type)dis[u.dest].first=dis[now.first].first+u.length;
                else dis[u.dest].first=min(dis[u.dest].first,dis[now.first].first+u.length);
                dis[u.dest].second=now.second;
            }
        }
        else{
            for(line u:stapla[now.first]){
                if((dis[u.dest].first==0x7f7f7f7f||dis[u.dest].second!=u.type)&&u.type==now.second)q.push({u.dest,u.type});
                if(now.second==u.type){
                    dis[u.dest].first=min(dis[u.dest].first,dis[now.first].first+u.length);
                    dis[u.dest].second=now.second;
                }
            }
        }
        cerr<<"Node "<<now.first<<" (Type "<<now.second<<") processed.\n";
        queue<pair<int,int> > q2;
        cerr<<"Queue: ";
        while(!q.empty()){
            q2.push(q.front());
            cerr<<'('<<q.front().first<<' '<<q.front().second<<')'<<"  ";
            q.pop();
        }
        cerr<<endl;
        while(!q2.empty()){
            q.push(q2.front());
            q2.pop();
        }
        cerr<<"Distance: ";
        for(int i=1;i<=m;i++){
            cerr<<dis[i].first<<' ';
        }
        cerr<<endl;
    }
    return dis[y].first;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>exsta[i];
    for(int i=1;i<=n;i++){
        int l,tmp;
        cin>>l;
        for(int j=1;j<=l;j++){
            int x,len;
            cin>>x>>len;
            stapla[x].push_back({i,len,x+m});
            stapla[x+m].push_back({i,len,x});
            if(j!=1){
                stapla[x].push_back({i,0,tmp});
                stapla[tmp].push_back({i,0,x});
            }
            tmp=x;
        }
    }
    cerr<<"Input Check\n";
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<exsta[x]+bfs(x+m,y+m)+exsta[y]<<endl;
    }
    return 0;
}
