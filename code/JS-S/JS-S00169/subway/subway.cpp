#include<bits/stdc++.h>
using namespace std;
namespace fastIO{
    const int N=1<<20;
    char buf[N],*p1=buf,*p2=buf;
    inline char getchar(){
        if(p1==p2){
            p2=(p1=buf)+fread(buf,1,N,stdin);
            if(p1==p2)return EOF;
        }
        return *p1++;
    }
    inline int read(){
        int x=0,f=1;
        char ch=getchar();
        while(ch<'0'||ch>'9'){
            if(ch=='-')f=-1;
            ch=getchar();
        }
        while(ch>='0'&&ch<='9'){
            x=(x<<1)+(x<<3)+(ch^48);
            ch=getchar();
        }
        return x*f;
    }
}
struct node{
    int id,waste;
};
const int N=5e5+505;
int c,n,m,d,q,w[N],a[505][505],t[505][505],k[505],ans;
vector<vector<node> >tu;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=fastIO::read();
    n=fastIO::read();
    m=fastIO::read();
    d=fastIO::read();
    q=fastIO::read();
    int dist[n+m+5][n+m+5];
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
            if(i==j)dist[i][j]=0;
            else if(tu[i][j].id){
                dist[i][j]=tu[i][j].waste;
            }else dist[i][j]=INT_MAX;
        }
    }
    for(int i=1;i<=m;i++)w[i]=fastIO::read();
    for(int i=1;i<=n;i++){
        k[i]=fastIO::read();
        for(int j=1;j<=k[i];j++){
            a[i][j]=fastIO::read();
            t[i][j]=fastIO::read();
            tu[j].push_back({m+i,t[i][j]});
        }
    }

    for(int i=1;i<=n;i++)for(int j=1;j<=k[i];j++)tu[j].push_back({m+i,t[i][j]+t[j][i]});
    queue<int>q1;
    q1.push(1);
    while(!q1.empty()){
        int x=q1.front();
        q1.pop();
        for(auto it:tu[x]){
            q1.push(it.id);
            for(int k=1;k<=n+m;k++){
                dist[x][it.id]=min(dist[x][it.id],dist[x][k]+dist[k][it.id]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y,duod=0;
        x=fastIO::read();
        y=fastIO::read();
        duod=w[x]+w[y];
        cout<<duod+dist[x][y];
    }
    return 0;
}
