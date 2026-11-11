#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+int(ch-'0');
        ch=getchar();
    }
    x*=f;
    return x;
}
int c,n,m,d,q1;
struct _l{
    int id;
    int vf,vn;
    int w;
};
struct _s{
    _l line[25];
    int cnt;
}a[500005];
int w[500005];
int nk[505];
map<pair<int,int>,int>ma2;
priority_queue</**/pair</**/int,pair<int,int>/**/ >,vector</**/pair<int,pair<int,int> >/**/ >,greater</**/pair<int,pair<int,int> >/**/ >/**/ >q,e;
int dijkstra(int bx,int by){
    q=e;
    q.push({0,{bx,0}});
    ma2[{bx,0}]=0;
    while(!q.empty()){
        pair<int,pair<int,int> > t_=q.top();
        q.pop();
        int w=t_.first,x=t_.second.first,y=t_.second.second;
        if(y==0){
            if(x==by) return w;
            for(int i=1;i<=a[x].cnt;i++){
                int ty=a[x].line[i].id,tw=a[x].line[i].w;
                if(ma2.count({x,ty})&&ma2[{x,ty}]<=w+tw) continue;
                q.push({w+tw,{x,ty} });
                ma2[{x,ty}]=w+tw;
            }
        }else{
            if(!(ma2.count({x,0})&&ma2[{x,0}]<=w+a[x].line[y].w)){
                q.push({w+a[x].line[y].w,{x,0}});
                ma2[{x,0}]=w+a[x].line[y].w;
            }
            int tx=a[x].line[y].vf;
            if(!(ma2.count({tx,y})&&ma2[{tx,y}]<=w)){
                q.push({w,{tx,y}});
                ma2[{tx,y}]=w;
            }
            tx=a[x].line[y].vn;
            if(!(ma2.count({tx,y})&&ma2[{tx,y}]<=w)){
                q.push({w,{tx,y}});
                ma2[{tx,y}]=w;
            }
        }
    }
    return 0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    c=read(),n=read(),m=read(),d=read(),q1=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        nk[i]=read();
        pair<int,int> b[25];
        for(int j=1;j<=nk[i];j++){
            int ai=read(),ti=read();
            b[j]=make_pair(ai,ti);
        }
        int v=b[1].first;
        a[v].line[++a[v].cnt].id=i;
        a[v].line[a[v].cnt].vf=-1;
        a[v].line[a[v].cnt].vn=b[2].first;
        a[v].line[a[v].cnt].w=b[1].second;
        for(int j=2;j<nk[i];j++){
            v=b[j].first;
            a[v].line[++a[v].cnt].id=i;
            a[v].line[a[v].cnt].vf=b[j-1].first;
            a[v].line[a[v].cnt].vn=b[j+1].first;
            a[v].line[a[v].cnt].w=b[j].second;
        }
        v=b[nk[i]].first;
        a[v].line[++a[v].cnt].id=i;
        a[v].line[a[v].cnt].vf=b[nk[i]-1].first;
        a[v].line[a[v].cnt].vn=-1;
        a[v].line[a[v].cnt].w=b[nk[i]].second;
    }
    for(int i=1;i<=q1;i++){
        int bx=read(),by=read();
        cout<<dijkstra(bx,by)+w[bx]+w[by]<<'\n';
    }
    return 0;
}
