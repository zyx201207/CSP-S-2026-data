#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200666,M=166;
int c,t,n,k,d[M][M],low[N];
vector<int>e[N];
bool o[N];
void dfs(int id,int rt){
    o[id]=true;
    for (auto i:e[id])if (!o[i]){
        d[rt][i]=d[rt][id]+1;
        dfs(i,rt);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    for (;t--;){
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) e[i].clear();
        for (int i=1,x,y;i<n;i++){
            scanf("%d%d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        if (n<=10){
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++) o[j]=false;
                d[i][i]=0;
                dfs(i,i);
            }
            int res=n;
            for (int i=0;i<(1<<n);i++){
                int l=0;
                for (int j=0;j<n;j++) if (1&(i>>j)) ++l;
                if (l!=k) continue;
                int ans=0;
                for (int x=0;x<n;x++)if (1^(i>>x)){
                    int cnt=n;
                    for (int y=0;y<n;y++)if (1&(i>>y))
                        cnt=min(cnt,d[x+1][y+1]);
                    ans=max(ans,cnt);
                }
                res=min(res,ans);
            }
            printf("%d\n",res);
            continue;
        }
        int ans=n;
        if (n==k){printf("0\n");continue;}
        int m=n/2;
        if (k>=m) ans=1;
        else ans=(m+1-k+3)/4+1;
        printf("%d\n",ans);
    }
    return 0;
}
