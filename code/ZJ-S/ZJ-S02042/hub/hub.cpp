#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> head[1000005];
int getint(){
    int x=0;
    char ch=getchar();
    while(!(ch>='0'&&ch<='9')){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x;
}
namespace subtask1{
    int ans=1e9;
    int vis[15];
    int vs[15];
    int lw[15],de[15];
    void dfs2(int u,int fa,int nr){
        // cout<<u<<" "<<fa<<" "<<nr<<endl;
        de[u]=de[fa]+1;
        if(vis[u]&&nr==fa){
            nr=u;
            vs[u]=1;
        }
        lw[u]=min(lw[u],de[u]-de[nr]);
        for(auto v:head[u]){
            if(v==fa) continue;
            dfs2(v,u,nr);
        }
    }
    void dfs(int x){
        // cout<<x<<" "<<k<<endl;
        if(x>k){
            for(int i=1;i<=n;i++){
                vs[i]=0;
                lw[i]=1e9;
                // cout<<vis[i];
            }
            // cout<<endl;
            int cnt=0;
            bool f=1;
            for(int i=1;i<=n;i++){
                if(!vs[i]&&vis[i]){
                    cnt++;
                    if(cnt>2){
                        f=0;
                        break;
                    }
                    dfs2(i,0,0);
                }
            }
            if(f){
                int mx=0;
                for(int i=1;i<=n;i++){
                    mx=max(mx,lw[i]);
                }
                // if(ans>mx){
                //     cout<<mx<<endl;
                //     for(int i=1;i<=n;i++){
                //         cout<<vis[i]<<","<<lw[i]<<" ";
                //     }
                //     cout<<endl;
                // }
                ans=min(ans,mx);
            }
            return;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=1;
                dfs(x+1);
                vis[i]=0;
            }
        }
    }
    void main(){
        ans=1e9;
        dfs(1);
        printf("%d\n",ans);
    }
}
namespace subtask2{
    void main(){
        int m=n/2;
        if(k==n){
            puts("0");
        }
        else if(k>=m){
            puts("1");
        }
        else{
            printf("%d\n",(m-k+3)/4+1);
        }
    }
}
// namespace subtask3{
//     int de[1005];
//     int de2[1005];
//     int rs[1005];
//     int rs2[1005];
//     bool vis[1005];
//     int f[1005][1005];
//     int siz[1005];
//     int tp[1005];
//     int rt;
//     int ans;
//     void dfs(int u,int fa){
//         de[u]=de[fa]+1;
//         rs[u]=de[u];
//         for(auto v:head[u]){
//             if(v==fa||vis[v]) continue;
//             dfs(v,u);
//             rs[u]=max(rs[u],rs[v]);
//         }
//     }
//     void dfs3(int u,int fa){
//         siz[u]=1;
//         for(int i=0;i<=k;i++){
//             f[u][k]=1e9;
//         }
//         f[u][1]=0;
//         for(auto v:head[u]){
//             if(v==fa||vis[v]) continue;
//             dfs3(v,u);
//             for(int j=siz[u]+siz[v];j>=0;j--){
//                 tp[j]=f[u][j];
//                 f[u][j]=1e9;
//             }
//             for(int j=min(siz[u],k);j>=1;j--){
//                 for(int k=min(siz[v],k-j);k>=0;k--){
//                     f[u][j+k]=min(f[u][j+k],max(f[v][k],tp[j]));
//                 }
//             }
//             siz[u]+=siz[v];
//         }
//         siz[u]++;
//         f[u][1]=min(f[u][1],max(0,rs[u]-de[u]));
//         f[u][0]=rs[u]-de[u]+1;
//         // cout<<u<<":"<<endl;
//         // for(int i=0;i<=k;i++){
//         //     cout<<f[u][i]<<",";
//         // }
//         // cout<<endl;
//     }
//     void dfs2(int u,int fa){
//         vis[u]=1;
//         if(fa==rt){
//             dfs(rt,0);
//             dfs3(rt,0);
//         }
//         if(fa!=0){
//             dfs(u,0);
//             dfs3(u,0);
//             int res=1e9;
//             for(int i=1;i<k;i++){
//                 res=min(res,max(f[u][i],f[rt][k-i]));
//                 // cout<<f[u][i]<<" "<<f[rt][k-i]<<endl;
//             }
//             for(int i=1;i<=n;i++){
//                 if(vis[i]&&i!=rt&&i!=u){
//                     res=max(res,max(de2[i]-de2[rt],de2[u]-de2[i]));
//                     for(auto v:head[i]){
//                         if(!vis[v]){
//                             res=max(res,max(de2[i]-de2[rt],de2[u]-de2[i])+rs2[v]-de2[u]);
//                         }
//                     }
//                 }
//             }
//             // cout<<rt<<" "<<u<<" "<<res<<endl;
//             ans=min(ans,res);
//         } 
//         for(auto v:head[u]){
//             if(v==fa) continue;
//             dfs2(v,u);
//         }
//         vis[u]=0;
//     }
//     void dfs4(int u,int fa){
//         de2[u]=de2[fa]+1;
//         rs2[u]=de2[u];
//         for(auto v:head[u]){
//             if(v==fa||rs[v]) continue;
//             dfs4(v,u);
//             rs2[u]=max(rs2[u],rs2[v]);
//         }
//     }
//     void main(){
//         ans=1e9;
//         for(int i=1;i<=n;i++){
//             dfs4(i,0);
//             rt=i;
//             dfs2(i,0);
//         }
//         printf("%d\n",ans);
//     }
// }
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=getint();
    t=getint();
    while(t--){
        n=getint();
        for(int i=1;i<=n;i++){
            head[i].clear();
        }
        k=getint();
        for(int i=1;i<n;i++){
            int u,v;
            u=getint();
            v=getint();
            head[u].push_back(v);
            head[v].push_back(u);
        }
        if(c<=3){
            subtask1::main();
        }
        else{
            if(13<=c&&c<=14){
                subtask2::main();
            }
            else{
                // if(c<=6){
                //     subtask3::main();
                // }
                puts("0");
            }
        }
    }
    return 0;
}