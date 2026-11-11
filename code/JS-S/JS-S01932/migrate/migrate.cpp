#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int c,t,n;
LL d,x[2000010],dis[5010][5010],cnt[5010][5010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(n<=5000){
            LL ans=0;
            memset(dis,0x3f,sizeof dis);
            memset(cnt,0,sizeof cnt);
            for(int i=1;i<=n;i++) dis[i][i]=0,cnt[i][i]=1;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int k=j-1;k>=i;k--){
                        if(x[j]-x[k]>d) break;
                        if(dis[i][j]>(LL)(dis[i][k]+1)){
                            dis[i][j]=(LL)(dis[i][k]+1);
                            cnt[i][j]=cnt[i][k];
                        }
                        else if(dis[i][j]==(LL)(dis[i][k]+1)){
                            cnt[i][j]++;
                        }
                        else break;
                    }
                    if(cnt[i][j]==2) ans++;
                }
            }
            cout<<ans<<endl;
        }else{

        }
    }
    return 0;
}
