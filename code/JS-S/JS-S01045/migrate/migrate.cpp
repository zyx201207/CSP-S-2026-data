#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN=2e6+10;
int c,t,n,ans=0;
ll d;
ll k[MN],dis[MN];
int cnt[MN],vis[MN];

int read(){
    int f=1,res=0;
    char ch; ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        res=res*10+ch-'0';
        ch=getchar_unlocked();
    }
    return res*f;
}

void dfs(int st,int u,int step){
    if(dis[u]<step&&u!=st) return;
    if(dis[u]==step&&u!=st){
        cnt[u]++;
    }else if(dis[u]>step&&u!=st){
        cnt[u]=1; dis[u]=step;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(abs(k[i]-k[u])<=d) dfs(st,i,step+1);
    }
    return;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(); t=read();
    for(int i=1;i<=t;i++){
        ans=0;
        n=read(); d=read();
        for(int j=1;j<=n;j++){
            k[j]=read();
        }
        for(int j=1;j<=n;j++){
            memset(dis,0x3f3f3f,sizeof(dis));
            memset(cnt,0,sizeof(cnt));
            memset(vis,0,sizeof(vis));
            dis[j]=0; vis[j]=1;
            dfs(j,j,0);
            for(int z=1;z<=n;z++){
                //cout<<cnt[z]<<" ";
                ans+=(cnt[z]==2);
            }
        }
        cout<<ans<<endl;
    }




    return 0;
}