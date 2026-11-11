#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,W[500010];
long long dis[510][510],ans;
struct station{
    int cnt=0,pas[30];
    long long tim[30];
}s[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%d",&W[i]);
    for(int i=1;i<=n;i++){
        int k,a,t;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d%d",&a,&t);
            s[a].cnt++;
            s[a].pas[s[a].cnt]=i;
            s[a].tim[s[a].cnt]=t;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=1ll*1e15;
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int k=1;k<=m;k++)
        for(int i=1;i<=s[k].cnt;i++)
            for(int j=1;j<=s[k].cnt;j++)
                if(i!=j){
                    dis[s[k].pas[i]][s[k].pas[j]]=min(s[k].tim[i]+s[k].tim[j],dis[s[k].pas[i]][s[k].pas[j]]);
                    dis[s[k].pas[j]][s[k].pas[i]]=dis[s[k].pas[i]][s[k].pas[j]];
                }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                dis[j][i]=dis[i][j];
            }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ans=1ll*1e15;
        for(int i=1;i<=s[x].cnt;i++)
            for(int j=1;j<=s[y].cnt;j++)
                ans=min(ans,s[x].tim[i]+s[y].tim[j]+dis[s[x].pas[i]][s[y].pas[j]]);
        ans+=W[x]+W[y];
        printf("%lld\n",ans);
    }
    return 0;
}
