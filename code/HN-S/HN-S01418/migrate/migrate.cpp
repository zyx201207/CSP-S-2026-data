#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define int long long
const int MAXN = 2e6+5;
const int TST1 = 5e3+5;

int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}

int n,d,a[MAXN];

int dis[TST1][TST1];
int sum[TST1][TST1];
void solve1(){
    memset(dis,0x3f,sizeof(dis));
    memset(sum,0,sizeof(sum));
    // for(int i=1;i<=n-1;i++) cout<<a[i+1]-a[i]<<' ';
    // cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n&&a[j]-a[i]<=d;j++) dis[i][j]=sum[i][j]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i<k&&k<j){

    if(dis[i][k]+dis[k][j]==dis[i][j]){
        sum[i][j]+=sum[i][k]+sum[k][j]-1;
        // cout<<i<<' '<<j<<' '<<k<<' '<<sum[i][j]<<' '<<dis[i][j]<<endl;
    }
    if(dis[i][k]+dis[k][j]<dis[i][j]){
        sum[i][j]=sum[i][k]+sum[k][j]-1,dis[i][j]=dis[i][k]+dis[k][j];
        
    }

                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=i+1;j<=n;j++){
    //         cout<<i<<' '<<j<<' '<<dis[i][j]<<' '<<sum[i][j]<<endl;
    //     }
    // }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans+=(sum[i][j]==2);
        }
    }
    cout<<ans<<endl;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c=read(),T=read();
    
    while(T--){
        n=read(),d=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        solve1();
    }
    return 0;
}