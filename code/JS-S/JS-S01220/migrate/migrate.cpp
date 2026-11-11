//U can do it!
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,t,x[N],nxt[N][25],ct[N][25],sm[N][25],co[N];
bool checko(int ts, int nx){
    if(nx==0)return true;
    return ts==1 or x[nx]-x[ts-1]>d;
}
bool tw(int ts,int nx){
    if(nx==0)return true;
    return ts<=2 or x[nx]-x[ts-2]>d;
}
void solve(){
    scanf("%lld %lld",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",x+i);
    }
    for(int i=n,j=n;i>=1;i--){
        while(j>1 and x[i]-x[j-1]<=d)j--;
        co[j]++;
        if(i!=j)co[i]++;
    }
    for(int i=1,j=1;i<=n;i++){
        while(j<n and x[j+1]-x[i]<=d)j++;
        if(j==i){
            nxt[i][0]=0;
            continue;
        }
        nxt[i][0]=j;
        ct[i][0]=!checko(i,j);
        sm[i][0]+=co[j];
    }
    for(int i=1;i<=23;i++){
        for(int j=1;j<=n;j++){
            nxt[j][i]=nxt[nxt[j][i-1]][i-1];
            ct[j][i]=ct[j][i-1]+ct[nxt[j][i-1]][i-1];
            sm[j][i]=sm[j][i-1]+sm[nxt[j][i-1]][i-1];   
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        /*
            shouxian, zhaodao diyige bushi weiyi d difang 
            ranh ,congnali kaishi ,lainxv weiyi ,sm de he
        */
       int nw=i;
       for(int j=23;j>=0;j--){
           if(ct[nw][j]-ct[i][0]==0){
               nw=nxt[nw][j];
           }
       }
       if(!nw)continue;
       int er=nxt[nw][0];
       if(!tw(nw,nxt[nw][0]))continue;
       ans+=co[er];
       for(int j=23;j>=0;j--){
           if(ct[er][j]==0){
                ans+=sm[er][j];
                er=nxt[er][j];
           }
       }
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%*d %lld",&t);
    while(t--){
        solve();
    }
    return 0;
}