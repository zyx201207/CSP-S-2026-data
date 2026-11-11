#include<bits/stdc++.h>
#define int long long

using namespace std;
const int MAXN=2e6+5;
int c,t,n,d;
int a[MAXN];
int tnt=0;
void dfs(int y,int cost,int now){
    if(cost>mi_road) return;
    if(now==y) {
        if(mi_road==cost){
            tnt++;
        }else if(mi_road>cost){
            tnt=1;
        }
        mi_road=min(cost,mi_road);
    }
    for(int i=now+1;i<=y;i++){
        if(a[i]-a[now]<=d){
            dfs(y,cost+1,i);
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                tnt=0;
                mi_road=MAXN;
                dfs(j,0,i);
                if(tnt==2){
                    ans++;
                }

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
