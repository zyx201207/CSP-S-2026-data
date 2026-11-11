#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=5005;
const int inf=1000000000000000000;
int c,T,x[maxn];
int dis[maxn][maxn];
int vis[maxn];
int ans,cnt;
int n,d;
struct node{
    int y,len;
};
queue <node> q;
void dfs(int st,int ed,int len,int now,int sum){
    if(sum>len) return;
    if(sum==len&&now==ed){
        cnt++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(i!=now) 
        dfs(st,ed,len,i,sum+dis[now][i]);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    if(c==11||c==12){
        while(T--){
            scanf("%lld%lld",&n,&d);
            for(int i=1;i<=n;i++){
                scanf("%lld",&x[i]);
            }
            int p=x[2]-x[1];
            int k=d/p;
            int anss=max(0ll,n-(2*k-1));
            if(d<2*p) {
                printf("0\n");
                continue;
            }
            printf("%lld\n",anss);
        }
    }
    else{
    for(int i=0;i<=5000;i++){
        for(int j=0;j<=5000;j++){
            dis[i][j]=inf;
        }
    }
    while(T--){
        ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dis[i][j]=inf;
            }
        }
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
            //dis[i][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d) dis[i][j]=dis[j][i]=1;
                else break;
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        //---
        /*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<dis[i][j]<<' ';
            }
            cout<<endl;
        }*/
        //---
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cnt=0;
                if(dis[i][j]==inf) continue;
                dfs(i,j,dis[i][j],i,0);
                //cout<<"end:"<<i<<' '<<j<<' '<<cnt<<endl;
                if(cnt==2) ans++;
            }
        }
        printf("%lld\n",ans/2);
    }
    }
    




    return 0;
}