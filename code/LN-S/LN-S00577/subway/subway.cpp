#include<bits/stdc++.h>
using namespace std;
const int h=500010;
vector<int> v[h];
long long w[h],t[550][550],a[550][550],k[550];
long long c,n,m,d,q;
int dis(int x,int y){
    bool f[h]={0};
    //memset(0x3f,g,sizeof(g));
    //g[x]=0;
    for(int i=1;i<=n;i++){
        int ui=-1;
        for(int j:v[i]){
            if(f[j]==0&&(ui==-1||a[i][j]<ui))
                ui=a[i][j];
        }
        f[ui]==1;
        for(int j:v[i]){
            if(!f[j]&&t[ui][j]+t[i][ui]<t[i][j])
                t[i][j]=t[ui][j]+t[i][ui];
        }
    }
    return t[x][y];
}
int ans=0;
int vis[500000];
int y;
void dfs(int x,int deep){
    if(x==y)
        ans=max(ans,deep);
    for(int i:v[x]){
        dfs(i,deep+1);
    }
}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];//,表示第 i 条线路经过的地铁站数
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];//表示第 i 条线路经过的第 j 个地铁站
            if(j>1){
            v[a[i][j]].push_back(a[i][j-1]);
            v[a[i][j-1]].push_back(a[i][j]);
            }
            cin>>t[i][j];//表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
        }
    }
    while(q--){
        long long x;
        cin>>x>>y;
        if(7<=c&&11>=c){
            int ans=w[x]+w[y];
            cout<<ans+dis(x,y);
        }
        else if(12<=c&&19>=c){
            int sum=w[x]+w[y];
            int T=t[1][1];
            ans=0;
            dfs(x,1);
            cout<<ans*T+sum;
        }
        //
        else{
         long long x;
        cin>>x>>y;
        if(7<=c&&11>=c){
            int ans=w[x]+w[y];
            cout<<ans+dis(x,y);
        }
        else if(12<=c&&19>=c){
            int sum=w[x]+w[y];
            int T=t[1][1];
            ans=0;
            dfs(x,1);
            cout<<ans*T+sum;
        }
    }
    }

}
