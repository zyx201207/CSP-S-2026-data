#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int sum[1000],a[N],bins[N][40],n,m,vis[N],fl,s,ans=(1<<32)-1;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        int tmp = a[i];
        int c = 0;
        while(tmp > 0){
            if(tmp & 1) {
                bins[i][c] = 1;
                sum[c]++;
            }
            c++;
            tmp /= 2;
        }
    }
    /*
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= 30;j++){
            cerr << bins[i][j] << " ";
        }
        cerr << endl;
    }
    for(int j = 0;j <= 30;j++) cerr << sum[j] << " ";
    cerr << endl;
    cerr << "-----------\n";*/
    for(int j = 30;j >= 0;j--){
            //cerr << j << " " << sum[j] << endl;
        if(sum[j] < m) continue;
    //cerr << 111<< endl;
        if(!fl){
                //cerr << 11111 << endl;
            fl = 1;
            s = sum[j];
            for(int i = 1;i <= n;i++){
                if(!(bins[i][j]))vis[i] = 1;
            }
            continue;
        }
        //cerr << "--- " << j << endl;
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(!vis[i] && !(bins[i][j])){
                cnt ++;
                //cerr << "cnt++ !!" << vis[j]  << " " << j<< " " << i << endl;
            }
        }
        //for(int i = 1;i <= n;i++) cerr << vis[i] << "<->" << i << " ";
        //cerr << endl << endl;
        //cerr << s << "---------" << cnt << endl;
        if(s-cnt < m)continue;
        //cerr << "ql" << endl;
        for(int i = 1;i <= n;i++){
            if(!vis[i] && !(bins[i][j]))vis[i] = 1;
        }
        s = s-cnt;
    }
    //for(int i = 1;i <= n;i++) cerr << vis[i] << " ";
    for(int i = 1;i <= n;i++) if(vis[i] == 0) ans &= a[i];
    cout << ans << endl;
    return 0;
}
//I want CSP-S 200+  thank the best CCF
