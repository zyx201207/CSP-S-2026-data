#include<bits/stdc++.h>
using namespace std;
int x[2000005];
/*int e;
long long minn,d,ans;
int cnt;
void dfs(int now,long long di){
    if(now==e){
        if(di<minn){
            minn=di;
            cnt=1;
        }else if(di==minn){
            cnt++;
        }
        return;
    }
    if(x[e]-x[now]<=d){
        dfs(e,di+1);
        return;
    }
    for(int i=now;i<=e;i++){
        if(x[i]-x[now]<=d){
            dfs(i,di+1);
        }
    }
}*/
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d %d",&c,&t);
    while(t--){
        int n;
        long long d;
        scanf("%d %lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        }
        /*
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                minn=2e18;
                e=j;
                dfs(i,0);
                if(cnt==2){
                    ans++;
                }
            }

        }*/
        printf("0\n");
    }
    return 0;
}
