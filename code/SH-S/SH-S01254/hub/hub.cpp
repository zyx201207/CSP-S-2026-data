#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int c,T,n,k,a1,a2,tot;
vector<int>g[1000010];
int f[1010][1010],lst[1010],siz[1010],cnt[2010][1010];
int dep[1010][1010];
vector<pair<int,int>>v;
bool vis[1010];
map<pair<int,int>,int>mp;
bool ok;
void dfs(int x,int fa){
    for(int y:g[x]){
        if(y==fa) continue;
        dfs(y,x);
    }
    lst[0]=1e9;
    for(int i=1;i<=k;i++){
        lst[i]=1e9;
        f[x][i]=1e9;
    }
    for(int y:g[x]){
        if(y==fa) continue;
        siz[x]+=siz[y];
        for(int i=0;i<=min(k,siz[x]);i++){
            lst[i]=f[x][i];
            f[x][i]=1e9;
        }
        for(int i=0;i<=min(k,siz[x]);i++){
            for(int j=0;j<=min(i,siz[y]);j++){
                if(j==0) f[x][i]=min(f[x][i],max(lst[i-j],f[y][j]+1));
                else f[x][i]=min(f[x][i],max(lst[i-j],f[y][j]));
            }
        }
    }
    siz[x]++;
    // if(f[x][0]==0){
    //     cerr<<(int)g[x].size()<<"cccc\n";
    // }
    for(int i=min(siz[x],k);i>0;i--){
        f[x][i]=f[x][i-1];
        //if(ok) cerr<<x<<" "<<i<<" "<<f[x][i]<<"fff\n";
    }
}
void dfs2(int x,int fa,int now){
    for(int y:g[x]){
        if(y==fa) continue;
        dep[now][y]=dep[now][x]+1;
        dfs2(y,x,now);
    }
}
void dfs3(int x,int fa){
    vis[x]=1;
    for(int y:g[x]){
        if(y==fa) continue;
        dfs3(y,x);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        v.clear();
        for(int i=1;i<=tot;i++){
            for(int j=1;j<=k;j++){
                cnt[i][j]=0;
            }
        }
        tot=0;
        for(int i=1;i<=n;i++){
            g[i].clear();
            for(int j=1;j<=k;j++){
                f[i][j]=1e9;
            }
        }
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>a1>>a2;
            g[a1].push_back(a2);
            g[a2].push_back(a1);
            v.push_back({a1,a2});
        }
        //if(T>=3) continue;
        // k=2;
        // ok=1;
        // dfs(8,1);
        // ok=0;
        int pr=1e9;
        for(int i=1;i<=n;i++){
            dep[i][i]=0;
            dfs2(i,0,i);
        }
        mp.clear();
        for(auto i:v){
            for(int x=1;x<=n;x++){
                siz[x]=0;
                for(int j=0;j<=k;j++){
                    f[x][j]=0;
                    lst[j]=0;
                }
            }
            dfs(i.ff,i.ss);
            mp[{i.ff,i.ss}]=++tot;
            for(int j=1;j<=k;j++){
                cnt[tot][j]=f[i.ff][j];
                //if(j>siz[i.ff]) cnt[tot][j]=1e9;
            }
            int temp=1e9;
            for(int j=1;j<=k;j++){
                temp=min(temp,f[i.ff][j]);
            }
            for(int j=1;j<=n;j++){
                if(siz[j]==0) temp=max(temp,dep[i.ff][j]);
            }
            pr=min(pr,temp);
            for(int x=1;x<=n;x++){
                siz[x]=0;
                for(int j=0;j<=k;j++){
                    f[x][j]=0;
                    lst[j]=0;
                }
            }
            dfs(i.ss,i.ff);
            mp[{i.ss,i.ff}]=++tot;
            for(int j=1;j<=k;j++){
                cnt[tot][j]=f[i.ss][j];
                //if(j>siz[i.ss]) cnt[tot][j]=1e9;
            }
            temp=1e9;
            for(int j=1;j<=k;j++){
                temp=min(temp,f[i.ss][j]);
            }
            for(int j=1;j<=n;j++){
                if(siz[j]==0) temp=max(temp,dep[i.ss][j]);
            }
            pr=min(pr,temp);
        }
        //cerr<<tot<<"ttt\n";
        //cerr<<cnt[mp[{8,1}]][4]<<"mmm\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                int pi,pj;
                for(int x:g[i]){
                    if(dep[j][x]==dep[j][i]-1){
                        pi=x;
                        break;
                    }
                }
                for(int x:g[j]){
                    if(dep[i][x]==dep[i][j]-1){
                        pj=x;
                        break;
                    }
                }
                for(int x=1;x<=n;x++) vis[x]=0;
                dfs3(i,pi),dfs3(j,pj);
                //cerr<<i<<" "<<j<<" "<<pi<<" "<<pj<<"ppp\n";
                int ans=1e9;
                int idi=mp[{i,pi}],idj=mp[{j,pj}];
                for(int x=1;x<k;x++){
                    ans=min(ans,max(cnt[idi][x],cnt[idj][k-x]));
                    // if(cnt[idi][x]==0&&cnt[idj][k-x]==0){
                    //     cerr<<x<<" "<<k<<" "<<(int)g[i].size()<<" "<<(int)g[j].size()<<"ggg\n";
                    // }
                    //if(i==2&&j==5)cerr<<i<<" "<<j<<" "<<pi<<" "<<x<<" "<<cnt[idi][x]<<" "<<cnt[idj][k-x]<<"ccc\n";
                }
                for(int x=1;x<=n;x++){
                    if(!vis[x]){
                        //if(i==2&&j==5) cerr<<x<<"xxx\n";
                        ans=max(ans,min(dep[x][i],dep[x][j]));
                    }
                }
                //if(ans==0) cerr<<i<<" "<<j<<"aaa\n";
                pr=min(pr,ans);
            }
        }
        cout<<pr<<'\n';
    }
}