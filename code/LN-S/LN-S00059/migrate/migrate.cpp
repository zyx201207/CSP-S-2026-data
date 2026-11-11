#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f;
const int maxn =2e6+10;
int c,t,n,d;
int a[maxn];
int cnt;
int sum;
int ans=0;
void dfs(int x,int y,int step){
    if(x==y) {
        if(ans>step){
            cnt=1;
            ans=step;
        }else if(ans==step) cnt++;
        return ;
    }
    for(int i=x+1;i<=y;i++){
        if(d>=a[i]-a[x]){
            dfs(i,y,step+1);
        }
    }
    return ;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        sum=0;
        cin>>n>>d;
        for(int i =1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=INF;
                cnt=0;
                dfs(i,j,0);
                if(cnt==2) sum++;
            }
        }
        cout<<sum<<'\n';
    }

    return 0;
}
