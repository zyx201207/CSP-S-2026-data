//author:lklklklklkl
//Why are you still here,an old Senior 3 WHKer?
//你是理所当然的奇迹，你是月色真美
//Encode:UTF-8
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,st,ed,ans;
int k[505],w[500005],s[500005];
struct node{
    int tr,tm;
};
vector<node> arr[500005];
int dis[505][505];
int r;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    node emp;
    emp.tm=emp.tr=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%lld%lld",&st,&r);
            s[st]++;
            arr[st].push_back(emp);
            arr[st][s[st]-1].tr=i;
            arr[st][s[st]-1].tm=r;
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=0;j<s[i];j++)
            for(int k=0;k<s[j];k++)
                dis[arr[i][j].tr][arr[i][k].tr]=dis[arr[i][k].tr][arr[i][j].tr]=min(dis[arr[i][j].tr][arr[i][k].tr],arr[i][j].tm+arr[i][k].tm);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=q;i++){
        scanf("%lld%lld",&st,&ed);
        ans=1e18;
        for(int j=0;j<s[st];j++)
            for(int k=0;k<s[ed];k++)
                ans=min(ans,w[st]+w[ed]+dis[arr[st][j].tr][arr[ed][k].tr]+arr[st][j].tm+arr[ed][k].tm);
        printf("%lld\n",ans);
    }
    return 0;
}
//Yellow or Green
//This and T3 can't be Cyan
//If this or T3 is Cyan,I will tell my crush that I love her
//14:46-15:38
//Oct31==Dec25?
