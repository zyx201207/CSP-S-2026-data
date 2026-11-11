// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// const int M=20+2;
// int c,t;
// int n,k;
// vector<int>G[N];
// int siz[N],dep[N];
// int st[N][M];
// int dp2[N],dp3[N];
// int dfn[N],dfnn[N],cnt;
// int l[N],r[N];
// void dfs(int now,int fa){
//     dfn[now]=++cnt;
//     dfnn[cnt]=now;
//     siz[now]=1;
//     dep[now]=dep[fa]+1;
//     st[now][0]=fa;
//     for(int i=1;i<=20;i++){
//         st[now][i]=st[st[now][i-1]][i-1];
//     }
//     l[now]=r[now]=dfn[now];
//     for(int x:G[now]){
//         if(x==fa)   continue;
//         dfs(x,now);
//         r[now]=r[x];
//         dp2[now]=max(dp2[now],dp2[x]+1);
//         siz[now]+=siz[x];
//     }
// }
// void dfss(int now,int fa){
//     int nowmax=0,nowid=0;
//     for(int x:G[now]){
//         if(x==fa)   continue;
//         if(nowmax>dp2[x]){
//             nowmax=dp2[x];
//             nowid=x;
//         }
//     }
//     int nowmax2=0;
//     for(int x:G[now]){
//         if(x==fa)   continue;
//         if(x==nowid)    continue;
//         nowmax2=max(nowmax2,dp2[x]);
//     }
//     if(!nowid)  continue;
//     dp3[nowid]=max(nowmax2+1,dp3[now])+1;
//     dfss(nowid,now);
//     for(int x:G[now]){
//         if(x==fa)   continue;
//         if(x==nowid)    continue;
//         dp3[x]=max(nowmax+1,dp3[now])+1;
//         dfss(x,now);
//     }
// }
// set<pair<int,int> >S;
// int find(int x,int kk){
//     for(int i=20;i>=0;i--){
//         if(kk>=(1<<i)){
//             kk-=(1<<i);
//             x=st[x][i];
//         }
//     }
//     return x;
// }
// int vis[N];
// int dp[N];
// void dfs2(int now,int fa){
//     for(int x:G[now]){
//         if(x==fa)   continue;
//         dfs2(x,now);
//         vis[now]=max(vis[now],vis[x]);
//         dp[now]+=dp[x];
//     }
//     if(vis[now])    dp[now]++;
// }
// int tr[4*N];
// void modify(int p,int l,int r,int x,int v){
//     if(l==r){
//         tr[p]=v;
//         return;
//     }
//     int mid=(l+r)/2;
//     if(x<=mid)  modify(2*p,l,mid,x,v);
//     else    modify(2*p+1,mid+1,r,x,v);
//     tr[p]=max(tr[2*p],tr[2*p+1]);
// }
// int qy(int p,int l,int r,int x,int k){
//     if(l>x) return -1;
//     if(l==r){
//         return (tr[p]>k)?l:-1;
//     }
//     int mid=(l+r)/2;
//     if(r<=x){
//         if(tr[2*p+1]>k)   return qy(2*p+1,mid+1,r,x,k);
//         else    return qy(2*p,l,mid,x,k);
//     }
//     int ans=qy(2*p+1,mid+1,r,x,k);
//     if(ans!=-1) return ans;
//     return qy(2*p,l,mid,x,k);
// }
// int flag[N],g[N];
// int st2[N][M];
// int qy2(int l,int r){
//     int xx=g[r-l+1];
//     return max(st2[l][xx],st2[r-(1<<xx)+1][xx]);
// }
// void dfs3(int now,int fa){
//     if(fa){
//         flag[now]=qy(1,1,n,dep[now]-1,k-dep[now]);
//     }
//     int nowid=0;
//     for(int x:G[now]){
//         if(x==fa)   continue;
//         if(dp2[x]+1==dp2[now]){
//             nowid=x;
//             break;
//         }
//     }
//     if(!nowid)  return;
//     int nowmax=0;
//     for(int x:G[now]){
//         if(x==fa)   continue;
//         if(x==nowid)    continue;
//         nowmax=max(nowmax,dp2[x]);
//     }
//     modfiy(1,1,n,dep[now],nowmax+1-dep[now]);
//     dfs3(nowid,now);
//     for(int x:G[now]){
//         if(x==fa)   continue;
//         modify(1,1,n,dep[now],dp2[now]+1-dep[now]);
//         dfs3(x,now);
//     }
// }
// bool chk(int x){
//     for(int i=1;i<=n;i++){
//         int xx=find(i,x);
//         vis[xx]=1;
//     }
//     dfs2(1,0);
//     /*for(int i=1;i<=n;i++){
//         modify(1,1,n,i,INT_MIN);
//     }*/
//     dfs3(1,0);
//     for(int i=1;i<=n;i++){
//         if(flag[i]==-1){
//             flag[i]=1;
//         }
//     }
//     for(int i=2;i<=n;i++){
//         int now=i;
//         for(int j=20;j>=0;j--){
//             if(st[now][j]){
//                 int y=st[now][j];
//                 int dis=dep[now]-dep[y];
//                 int yy=find(now,dis/2);
//                 if(flag[i]<dep[yy]){
//                     //max((l[y],r[y])\(l[yy],r[yy]))

//                 }
//             }
//         }
//     }
// }
// int main(){
//     cin>>c>>t;
//     while(t--){
//         cin>>n>>k;
//         int u,v;
//         for(int i=1;i<n;i++){
//             cin>>u>>v;
//             G[u].push_back(v);
//             G[v].push_back(u);
//         }
//         dfs(1,0);
//         dfss(1,0);
//         //dfs4(1,0);
//         for(int i=1;i<=n;i++){
//             g[i]=-1;
//         }
//         int tot=0;
//         for(int i=1;i<=n;i*=2){
//             g[i]=tot;
//             tot++;
//         }
//         for(int i=1;i<=n;i++){
//             if(!g[i]){
//                 g[i]=g[i-1];
//             }
//         }
//         for(int i=n;i>=1;i--){
//             st2[i][0]=dep[dfnn[i]];
//             for(int j=1;j<=20;j++){
//                 st2[i][j]=max(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
//             }
//         }
//         int l=0,r=n,ans=-1;
//         while(l<=r){
//             int mid=(l+r)/2;
//             if(chk(mid)){
//                 ans=mid;
//                 r=mid-1;
//             }
//             else{
//                 l=mid+1;
//             }
//         }
//         cout<<ans<<"\n";
//     }
// }
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=20+2;
int c,t;
int n,k;
vector<int>G[N];
int vis[N];
int dp[N];
int dep[N];
int st[N][M];
void dfs(int now,int fa){
    dep[now]=dep[fa]+1;
    st[now][0]=fa;
    for(int i=1;i<=5;i++){
        st[now][i]=st[st[now][i-1]][i-1];
    }
    if(vis[now]){
        dp[now]=1;
        for(int xx:G[now]){
            if(xx==fa)  continue;
            dfs(xx,now);
            if(vis[xx]){
                dp[now]+=dp[xx]-1;
            }
            else    dp[now]+=dp[xx];
        } 
    }
    else{
        for(int xx:G[now]){
            if(xx==fa)  continue;
            dfs(xx,now);
            dp[now]+=dp[xx];
        } 
    }
}
int dis[N];
int lca(int x,int y){
    if(dep[x]<dep[y])   swap(x,y);
    for(int i=5;i>=0;i--){
        if(dep[st[x][i]]>=dep[y]){
            x=st[x][i];
        }
    }
    if(x==y)    return x;
    for(int i=5;i>=0;i--){
        if(st[x][i]!=st[y][i]){
            x=st[x][i],y=st[y][i];
        }
    }
    return st[x][0];
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(c==13 || c==14){
            if(k==n){
                cout<<0<<"\n";
            }
            else if(k>=(n-1)/2){
                cout<<1<<"\n";
            }
            else{
                int m=(n-1)/2;
                int anss=(m/k)+((m%k)!=0);
                anss=anss/2+(anss%2);
                //cout<<k<<" "<<m<<"\n";
                cout<<anss+1<<"\n";
            }
            continue;
        }
        int ans=INT_MAX;
        for(int i=0;i<(1<<n);i++){
            int tots=0;
            for(int j=1;j<=n;j++){
                if((i&(1<<(j-1)))){
                    vis[j]=1;
                    tots++;
                }
                else    vis[j]=0;
            }
            if(tots!=k) continue;
            for(int j=1;j<=n;j++){
                dp[j]=0;
            }
            dfs(1,0);
            /*if(i==10){
                cout<<"#"<<"\n";
                cout<<dp[1]<<" "<<dp[2]<<" "<<dp[3]<<" "<<dp[4]<<" "<<dp[5]<<"\n";
            }*/
            if(dp[1]>2) continue;
            int anss=0;
            for(int j=1;j<=n;j++){
                dis[j]=INT_MAX;
                for(int z=1;z<=n;z++){
                    if(vis[z]){
                        int xx=lca(j,z);
                        dis[j]=min(dis[j],dep[j]+dep[z]-2*dep[xx]);
                    }
                }
                /*if(i==10){
                    cout<<dis[j]<<" ";
                }*/
                anss=max(anss,dis[j]);
            }
            //cout<<"\n";
            ans=min(ans,anss);
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++){
            G[i].clear();
            dp[i]=0;
        }
    }
    return 0;
}