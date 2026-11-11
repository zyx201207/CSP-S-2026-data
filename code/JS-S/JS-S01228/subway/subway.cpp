#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[505][25];
ll t[505][25];
ll w[500005];
ll k[505];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    ll T=t[1][1];
    bool flag1=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            if(t[i][j]!=T){
                flag1=false;
            }
        }
    }
    if(flag1){
        while(q--){
            int x,y;
            cin >> x >> y;
            ll sum=0;
            sum+=w[x];
            sum+=w[y];
            
        }
    }else{
        while(q--){
            int x,y;
            cin >> x >> y;
            ll sum=0;
            sum+=w[x];
            sum+=w[y];

        }
    }
    return 0;
}