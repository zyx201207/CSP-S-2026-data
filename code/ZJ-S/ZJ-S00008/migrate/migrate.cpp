#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int c,T,n;
long long d,a[maxn],dp[maxn],dis[maxn],b[maxn],lst[maxn],ans,pre[maxn];
void init(){
    for(int i=1;i<=n;i++){
        dis[i]=0;
        dp[i]=1;
        lst[i]=0;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>T;
    while(T--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(c==11 || c==12){
            int x=d/(a[2]-a[1]);
            if(x<=1 || x>=n) ans=0;
            else ans=max(n-(2*x)+1,0);
            cout<<ans<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            b[i]=max(1ll,lower_bound(a+1,a+i+1,a[i]-d)-a);
        }
        for(int i=1;i<=n;i++){
            init();
            dis[i]=0;dp[i]=1;
            lst[0]=i;
            pre[i-1]=0;pre[i]=1;
            for(int j=i+1;j<=n;j++){
                int p=max(b[j],1ll*i);
                dis[j]=dis[p]+1;
                dp[j]=pre[lst[dis[p]]]-pre[p-1];
                if(dp[j]==2) ans++;
                lst[dis[j]]=j;
                pre[j]=pre[j-1]+dp[j];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}