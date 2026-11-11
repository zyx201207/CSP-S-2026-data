#include <bits/stdc++.h>
using namespace std;
const int N=2000100;
typedef long long ll;
const int Inf=0x3f3f3f3f;
vector<int> a[N];
bool vis[N];
int len=0;
int dis[N];
void dfs(int u,int fa){
    dis[u]=dis[fa]+1;
    if (vis[u]){
        len=max(len,dis[u]);
        return;
    }
    for (auto v : a[u]){
        if (v==fa) continue;
        dfs(v,u);
    }
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,Tcs;
    scanf("%d%d",&c,&Tcs);
    while (Tcs--){
        int n,k;
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) a[i].clear();
        for (int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        /*
        dfs(1,0);
        int maxn=0,maxi;
        for (int i=1;i<=n;i++){
            if (dis[i]>maxn){
                maxn=dis[i];
                maxi=i;
            }
        }
        memset(dis,0,sizeof dis);
        dfs(maxi,0);
        maxn=0;
        int maxj;
        for (int i=1;i<=n;i++){
            if (dis[i]>maxn){
                maxn=dis[i];
                maxj=i;
            }
        }
        while (maxj){
            t.push_back(maxj);
            maxj=ft[maxj];
        }
        random_shuffle(t.begin(),t.end());
        */
        int ans=Inf;
        for (int i=0;i<(1<<n);i++){
            for (int j=1;j<=n;j++) vis[j]=0;
            int cnt=0;
            for (int j=0;j<n;j++){
                if (i&(1<<j)){
                    cnt++;
                    vis[j+1]=1;
                }
            }
            if (cnt>k) continue;
            int res=0;
            for (int j=1;j<=n;j++){
                dfs(j,0);
                res=max(res,len);
            }
            ans=min(ans,res);
        }
        printf("%d\n",ans);
    }
    return 0;
}
