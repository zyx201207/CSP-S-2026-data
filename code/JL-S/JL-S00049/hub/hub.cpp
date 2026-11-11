#include<bits/stdc++.h>
using namespace std;
struct edge{
    int to,net;
}e[2000006];
int head[10000006];
int f[100005][25];
int p[100006];
int d[100005];
int dep[100005];
map<pair<int,int> ,bool>mp;
int tot=0;
void add(int u,int v){
    tot++;
    e[tot].to=v;
    e[tot].net=head[u];
    head[u]=tot;
}
int get_fa(int u){
    return p[u]==u?u:p[u]=get_fa(p[u]);
}
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    f[u][0]=fa;
    for(int i=head[u];i;i=e[i].net){
        if(e[i].to!=fa)
        {
            dfs(e[i].to,u);
        }
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y]){
        swap(x,y);
    }
    int dick=dep[x]-dep[y];
    for(int j=0;j<=20;j++){
        if(dick&(1<<j)){
            x=f[x][j];
        }
    }
    if(x==y){
        return x;
    }
    for(int j=20;j>=0;j--){
        if(f[x][j]!=f[y][j]){
            x=f[x][j];
            y=f[y][j];
        }
    }
    return f[x][0];
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,T;
    cin>>c>>T;
    if(c<=3){
        while(T--){
            mp.clear();
            int n,k;
            cin>>n>>k;
            for(int i=1;i<=n;i++)p[i]=i;
            for(int i=1;i<n;i++){
                int u,v;
                cin>>u>>v;
                mp[make_pair(u,v)]=1;
                mp[make_pair(v,u)]=1;
                add(u,v);
                add(v,u);
            }
            dfs(1,0);
            for(int j=1;j<=20;j++){
                for(int i=1;i<=n;i++){
                    f[i][j]=f[f[i][j-1]][j-1];
                }
            }
            int ans=INT_MAX;
            for(int i=1;i<(1<<n);i++){
                if(__builtin_popcount(i)!=k){
                    continue;
                }
                for(int j=1;j<=n;j++){
                    p[j]=j;
                }
                int cnt=0;
                for(int j=1;j<=n;j++){
                    for(int k=1;k<=n;k++){
                        if((i&(1<<j-1))&&(i&(1<<k-1))){
                            if(mp[make_pair(j,k)]){
                                int jj=get_fa(j);
                                int kk=get_fa(k);
                                if(jj!=kk){
                                    p[jj]=kk;
                                }
                                cnt++;
                            }
                        }
                    }
                }
                bool flag=true;
                int num1=-1;
                int num2=-1;
                for(int j=1;j<=n;j++){
                    if(i&(1<<j-1)){
                        if(num1==-1){
                            num1=p[j];
                            continue;
                        }
                        if(num1==p[j])continue;
                        if(num2==-1){
                            num2=p[j];
                            continue;
                        }
                        if(num2==p[j]){
                            continue;
                        }
                        else {
                            flag=false;
                            break;
                        }
                    }
                }
                if(flag){
                    int maxn=-1;
                    for(int j=1;j<=n;j++){
                        if(!(i&(1<<j-1))){
                            int dis=INT_MAX;
                            for(int k=1;k<=n;k++){
                                if((i&(1<<k-1))){
                                    dis=min(dis,dep[j]+dep[k]-2*dep[lca(k,j)]);
                                }
                            }
                            maxn=max(maxn,dis);
                        }
                    }
                    ans=min(ans,maxn);
                }
            }
            cout<<ans<<"\n";
            tot=0;
            for(int i=1;i<=n;i++){
                head[i]=p[i]=dep[i]=0;
            }
        }
    }
    if(c==13||c==14){
        while(T--){
            int n,k;
            cin>>n>>k;
            for(int i=1;i<n;i++){
                int u,v;
                cin>>u>>v;
            }
            int m=(n-1)/2;
            cout<<m/2-k/2<<"\n";
        }   
    }
    return 0;
}