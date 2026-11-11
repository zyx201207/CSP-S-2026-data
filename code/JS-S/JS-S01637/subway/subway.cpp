#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,_,w[1005],a[505][1005],t[505][1005],k[1005],djgz[1005][505];
bool vis[505][1005];
vector<int>st[1005];
struct node{
    int road,sta,time;
};
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),_=read();
    for(int i=1;i<=m;i++)
        w[i]=read();
    for(int i=1;i<=n;i++){
        k[i]=read();
        for(int j=1;j<=k[i];j++){
            a[i][j]=read();t[i][j]=read();
            st[a[i][j]].push_back(i);
            djgz[a[i][j]][i]=j;
        }
    }
    while(_--){
        int x=read(),y=read(),minn=2147483647;
        queue<node>q;
        memset(vis,0,sizeof vis);
        for(int i=0;i<st[x].size();i++){
            vis[st[x][i]][djgz[x][st[x][i]]]=1;
            q.push({st[x][i],x,w[x]+t[st[x][i]][djgz[x][st[x][i]]]});
        }
        while(!q.empty()){
            node u=q.front();
            q.pop();
            if(u.sta==y){
                cout<<u.time+w[y]+t[u.road][djgz[y][u.road]]<<endl;
                break;
            }
            for(int i=0;i<st[u.sta].size();i++){
                int nr=st[u.sta][i];
                if(nr!=u.road&&!vis[nr][djgz[u.sta][nr]]){
                    vis[nr][djgz[u.sta][nr]]=1;
                    q.push({nr,u.sta,u.time+t[nr][djgz[u.sta][nr]]+t[u.road][djgz[u.sta][u.road]]});
                }
            }
            for(int j=1;j<=k[u.road];j++)
                if(!vis[u.road][j]){
                    vis[u.road][j]=1;
                    q.push({u.road,a[u.road][j],u.time});
                }
        }
    }
    return 0;
}
