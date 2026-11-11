#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 5005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll c,t,n,d,cnt = 0;
ll a[MAXN];
ll f[MAXN][MAXN];
ll leng[MAXN][MAXN];
bool cal(ll x,ll y){
    return (y - x <= d);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("migrate.in",'r',stdin);
    freopen("migrate.out",'w',stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        cnt = 0;
        for(ll i = 1;i <= n;i++) cin>>a[i];
        for(ll i = 1;i <= n;i++){
            for(ll j = i;j <= n;j++){
                if(cal(a[i],a[j])){
                    f[i][j] = 1;
                    leng[i][j] = 1;
                }
                else{
                    f[i][j] = 0;
                    leng[i][j] = INF;
                }
            }
        }
        for(ll len = 2;len <= n;len++){
            for(ll l = 1;l + len - 1 <= n;l++){
                ll r = l + len - 1;
                for(ll k = l + 1;k < r;k++){
                    if(leng[l][k] + leng[k][r] < leng[l][r]){
                        f[l][r] = 1;
                        leng[l][r] = leng[l][k] + leng[k][r];
                    }else if(leng[l][k] + leng[k][r] == leng[l][r]){
                        f[l][r] += 1;
                    }
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = i;j <= n;j++){
                if(f[i][j] == 2) cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
