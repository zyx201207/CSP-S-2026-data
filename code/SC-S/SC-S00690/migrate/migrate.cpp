#include<bits/stdc++.h>
#define ll long long
using namespace std;
int bjt[2000005],mind[2000005];
ll que[2000005],dep[2000005],n,d,a[2000005],ans=0;
void bfs(ll s){
    ll t=1;
    que[1]=s;
    for(int i=1;i<=t;i++){
        ll now=que[i];
        for(int j=now+1;j<=n;j++){
            if(a[j]-a[now]>d)break;
            if(bjt[j]&&mind[j]==dep[i]+1){
                que[++t]=j,dep[t]=dep[i]+1;
                bjt[j]++;
            }
            else if(bjt[j]==0){
                bjt[j]++;
                mind[j]=dep[i]+1;
                que[++t]=j,dep[t]=dep[i]+1;
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)bjt[j]=0,mind[j]=0;
            bfs(i);
            for(int j=1;j<=n;j++){
                if(bjt[j]==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}