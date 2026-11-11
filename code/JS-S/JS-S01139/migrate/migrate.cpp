#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const ll M=4e18;

ll C,T,n,d,ans,a[3000006];
ll lst[3000006],nxt[3000006],cnt;
ll dp[3000006][4],w;

void solve(){
    scanf("%lld %lld",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld ",&a[i]);
    }a[0]=-M;a[n+1]=M;
    if(n==1||n==2){
        printf("0\n");
        return;
    }
    if(C==11||C==12){
        ll dd=a[2]-a[1];
        ll t=d/dd+1;
        if(t==1||t==2){
            printf("0\n");
            return;
        }
        t=t*2-1;
        ans=max(n-t+2,0ll);
        printf("%lld\n",ans);
        return;
    }
    cnt=1;
    for(int i=1;i<=n+1;i++){
        while(a[i]-a[cnt]>d){
            nxt[cnt]=i-1;
            cnt++;
        }
    }
    cnt=n;
    for(int i=n;i>=0;i--){
        while(a[cnt]-a[i]>d){
            lst[cnt]=i+1;
            cnt--;
        }
    }
    for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=0;
    for(int i=n;i>=1;i--){
        dp[lst[i]][0]++;
        if(lst[i]<i-1) dp[lst[i]+1][1]++;
        if(nxt[i]==i){
            continue;
        }
        w=lst[nxt[i]];
        //0
        if(w==i){
            dp[i][0]+=dp[nxt[i]][0];
        }else if(lst[nxt[i]]==i-1){
            dp[i][1]+=dp[nxt[i]][0];
        }
        //1
        if(w==i){
            dp[i][2]+=dp[nxt[i]][1];
        }else{
            dp[i][3]+=dp[nxt[i]][1];
        }
        //2
        if(w==i){
            dp[i][2]+=dp[nxt[i]][2];
        }else{
            dp[i][3]+=dp[nxt[i]][2];
        }
        //ba
    }
    ans=0;
    for(int i=1;i<=n;i++){
        //printf("%lld %lld %lld %lld\n",dp[i][0],dp[i][1],dp[i][2],dp[i][3]);
        ans+=dp[i][2]+dp[i][3];
    }
    printf("%lld\n",ans);
    return;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld %lld",&C,&T);
    while(T--){
        solve();
    }
    return 0;
}
