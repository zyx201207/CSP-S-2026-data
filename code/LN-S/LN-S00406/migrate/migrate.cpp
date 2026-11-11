#include <cstdio>
#define ll long long
using namespace std;
ll f[2000005][3];
ll x[2000005],d;
int ezgs[2000005],pos[2000005];
int c,t,n;
signed main(){//duo ce qing kong
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
            ezgs[i]=0;
        }
        for(int i=1,j=1;i<=n;i++){
            while(x[j]-x[i]<=d && j<=n){
                j++;
            }
            if(j-1!=i){
                ezgs[j-1]++;
            }
        }
        for(int i=n,j=n;i>=1;i--){
            while(x[i]-x[j]<=d && j>=1){
                j--;
            }
            pos[i]=j+1;
        }
        for(int i=1;i<=n;i++){
            f[i][0]=ezgs[i];
            f[i][1]=0;
            f[i][2]=0;
            if(pos[i]<i && (i+1>n || x[i+1]-x[pos[i]]>d)){
                f[i][0]+=f[pos[i]][0];
                f[i][1]+=f[pos[i]][1];
            }
            if(pos[i]+1<i && (i+1>n || x[i+1]-x[pos[i]+1]>d)){
                f[i][1]+=f[pos[i]+1][2];
            }
            if(i>=2){
                f[i][2]=ezgs[i];
                if(pos[i-1]<i && x[i]-x[pos[i-1]]<=d && (i+1>n || x[i+1]-x[pos[i-1]]>d)){
                    f[i][2]+=f[pos[i-1]][0];
                }
                if(x[i]-x[i-1]<=d && (i+1>n || x[i+1]-x[i-1]>d)){
                    f[i][2]--;
                }
            }
            /*for(int j=0;j<=2;j++){
                printf("i:%d b:%d f:%lld\n",i,j,f[i][j]);
            }*/
            //printf("i:%d pos:%d ezgs:%d\n",i,pos[i],ezgs[i]);
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(pos[i]<i){
                ans+=f[pos[i]][1];
                //printf("i:%d ly:i:%d b:1 f:%lld\n",i,pos[i],f[pos[i]][1]);
            }
            if(pos[i]+1<i){
                ans+=f[pos[i]+1][2];
                //printf("i:%d ly:i:%d b:2 f:%lld\n",i,pos[i]+1,f[pos[i]+1][2]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
//9