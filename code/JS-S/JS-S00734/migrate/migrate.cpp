#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[105];
int cnt,mi;
void dg(int u,int v,int st){
    if(u==v){
        if(st<mi){
            mi = st;
            cnt = 0;
        }
        if(st==mi) cnt++;
        return ;
    }else{
        for(int i = u+1;i<=v;i++){
            if(x[i]-x[u]<=d){
                dg(i,v,st+1);
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i<=n;i++){
            cin >> x[i];
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            for(int j = i+3;j<=n;j++){
                cnt = 0;
                mi = 1e9+10;
                dg(i,j,0);
                if(cnt==2) ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}