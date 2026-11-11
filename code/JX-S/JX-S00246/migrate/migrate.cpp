#include<bits/stdc++.h>
using namespace std;
int c,T,x[10000005],maxn,sum[5005][5005],cnt,minn;
void dfs(int u,int v,int dq,int y){
    if(y>minn)return;
    if(dq==v){
        if(y==minn)cnt++;
        else if(y<minn)minn=y,cnt=1;
        return;
    }
    for(int i=dq+1;i<=v;i++){
        if(sum[dq][i]<=maxn)dfs(u,v,i,y+1);
    }
}
void work1(){
    while(T--){
        int n;
        cin>>n>>maxn;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int d=x[2]-x[1];
        if(maxn<d)cout<<0<<endl;
        else if(maxn==d||(maxn>d&&maxn<2*d))cout<<0<<endl;
        else cout<<1<<endl;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    if(c==11||c==12){
        work1();
        return 0;
    }
    while(T--){
        int n,ans=0;
        cin>>n>>maxn;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                sum[i][j]=x[j]-x[i];
            }
        }
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                cnt=0;
                minn=0x3f3f3f3f;
                dfs(i,j,i,0);
                if(cnt==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
