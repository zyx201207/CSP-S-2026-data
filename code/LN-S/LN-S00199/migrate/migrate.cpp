#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d,a[9114514],mp[5120][5120],mplinen[5120][5120];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        memset(a,0,sizeof(a));
        memset(mp,1LL,sizeof(mp));
        memset(mplinen,0,sizeof(mplinen));
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                 if(abs(a[i]-a[j])<=d){
                    mp[i][j]=1;
                    mplinen[i][j]=0;
                    //printf("newpath%lld->%lld\n",a[i],a[j]);
                 }
            }
        }
        bool flag=1;
        while(flag){
            flag=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    for(int k=i+1;k<=n;k++){
                        if(mp[i][k]>mp[i][j]+mp[j][k]){
                            mplinen[i][k]=0;
                            mp[i][k]=mp[i][j]+mp[j][k];
                        }
                        if(mp[i][k]==mp[i][j]+mp[j][k]){
                            mplinen[i][k]++;
                            //printf("path%lld->%lld->%lld\n",i,j,k);
                        }
                    }
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                //printf("%lld-%lld:%lld\n",i,j,mplinen[i][j]);
                if(mplinen[i][j]==2) ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

