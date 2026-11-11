#include <bits/stdc++.h>
using namespace std;
const int MN=1e6;
int c,n,m,d,p;
int w[MN];
vector<pair<int,int>> g[MN];


int read(){
    int f=1,res=0;
    char ch; ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        res=res*10+ch-'0';
        ch=getchar_unlocked();
    }
    return res*f;
}

int dij(int s,int e){
    priority_queue<pair<int,int>> q;
    int dis[MN];
    memset(dis,0x3f3f3f,sizeof(dis));
    q.push(make_pair(s,0)); dis[s]=0;
    //cout<<1<<endl;
    while(!q.empty()){
        pair<int,int> u=q.top(),v; q.pop();
        int l=g[u.first].size();
        for(int i=0;i<l;i++){
            v=g[u.first][i];
            if(dis[v.first]>dis[u.first]+v.second){
                dis[v.first]=dis[u.first]+v.second;
                q.push(make_pair(v.first,dis[v.first]));
            }
        }
    }
    return dis[e];
}


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(); n=read(); m=read(); d=read(); p=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1,x,y,z;i<=n;i++){
        x=read();
        for(int j=1;j<=x;j++){
            y=read(); z=read();
            g[i].push_back(make_pair(y+n,z));
            g[y+n].push_back(make_pair(i,z));
        }
    }
    for(int i=1,x,y;i<=p;i++){
        x=read(); y=read();
        cout<<w[x]+w[y]+dij(n+x,n+y)<<endl;
    }



    return 0;
}