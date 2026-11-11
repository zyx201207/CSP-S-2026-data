#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
int n,m;
ll ans;
ll a[200005];
int base[200005][35];  //0-34;
bool vis[200005];
int tmp[35];
int tot;
inline void trans(int i){
    tot=0;
    ll x=a[i];
    while (x){
        tmp[++tot]=(x&1);
        x/=2;
    }
    for (int j=31;j>=31-tot+1;j--){
        base[i][j]=tmp[31-j+1];
    }
}

int main (){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        trans(i);
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=31;j++){
    //         cout << base[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    memset(vis,true,sizeof(vis));
    for (int mask=1;mask<=31;mask++){
        int cnt=0;
        for (int i=1;i<=n;i++){
            if (vis[i]&&base[i][mask]==1){
                cnt++;
            }
        }
        if (cnt>=m){
            for (int i=1;i<=n;i++){
                if (base[i][mask]!=1) vis[i]=false;
            }
            ans+=(1ll<<(31-mask));
        }
    }
    cout << ans << endl;
    return 0;
}