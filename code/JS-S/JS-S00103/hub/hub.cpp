#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll ans;
ll x[N],dis[N],tme[N];
int n,d;
void dfs(int now,int tms){
//    dis[now]=min(dis[now],tmes);
    if(now>n){
        return ;
    }
    if(tms<dis[now]){
        tme[now]=0;
        dis[now]=tms;
        if(tme[now]==2) ans--;
    }else if(tms==dis[now]){
        tme[now]++;
        if(tme[now]==2) ans++;
        else if(tme[now]==3) ans--;
    }

    for(int i=now+1;i<=n&&x[now]+d>=x[i];i++){
        dfs(i,tms+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        bool flag1=1;
        for(int i=1;i<=n;i++) dis[i]=2e18;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            //if(i>1&&x[i]-1!=x[i-1])
        }
        dfs(1,0);
//        for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
//        cout<<endl;
        cout<<ans+1<<endl;
    }
    return 0;
}
