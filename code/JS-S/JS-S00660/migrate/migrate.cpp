#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,c,t,dis[1005][1005],f[1005],cnt[1005][1005];
ll a[1005],d;
void slove(){
    cin>>n>>d;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                dis[i][j]=200000000;
                cnt[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[i][i+1]=dis[i][i+1]=1;
        dis[i][i]=0;

    }
    for(int i=1;i<=n;i++)f[i]=1;
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
              if(abs(a[i]-a[j])<=d){
                dis[i][j]=dis[j][i]=1;
                cnt[i][j]=cnt[j][i]=1;
                f[i]++;
              }
        }
    }
    for(int len=3;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
            for(int k=i+1;k<=min(j,i+f[i]);k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
            for(int k=i+1;k<=min(j,i+f[i]);k++){
                if(dis[i][k]+dis[k][j]==dis[i][j])cnt[i][j]+=cnt[k][j];
            }
            if(cnt[i][j]==2){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return ;
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t){
    slove();
    t--;
}
return 0;
}
