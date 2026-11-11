#define dps 799
#define I dryer
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<ctime>
#include<vector>
using namespace std;
#define int long long
typedef vector<int> vv;
#define x first
#define y second
#define pb push_back
typedef pair<int,int> pii;
typedef vector<pii> vp;
typedef vector<vv> vvv;
const int N = 5105;
int a[N];
int nxt[N];
int b[2001000];
inline void sla(){
    int T;cin>>T;while(T--){
        int n,d;cin>>n>>d;
        for(int i=1;i<=n;++i) cin >> b[i];
        if(n==1){
            cout << 0 << endl; continue;
        }
        int dt = b[2]-b[1];
        int tm = d/dt;
        if(tm == 0) {
            cout << 0 << endl; continue;
        }
        if(tm == 1) {
            cout << 0 << endl; continue;
        }
        // if(tm > 2) {
        //     cout << 0 << endl; continue;
        // }
        //tm == 2
        int cnt = 0;
        int tt = tm*2-1; 
        for(int i=1;i<=n;++i) if(i+tt <= n) ++ cnt;
        cout << cnt << endl;
    }
}
inline void slb(){

}
int dsval[N];
int mval[N], mdst[N];
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("migrate.in","r",stdin); freopen("migrate.out","w",stdout);
    int c;cin>>c;
    if(c==11||c==12){
        return sla(), 0;
    }
    if(c==13||c==14){
        return slb(), 0;
    }
    int T;cin>>T;
    while(T--){
        int n,d; cin >> n >> d;
        for(int i=1;i<=n;++i) {
            cin >> a[i];
        }
        int cnt = 0;
        for(int i=1;i<=n;++i){
            int l = i;
            mdst[i] = 0; mval[i] = 1; dsval[0] = 1;
            int nowmn = 0;
            for(int j=i+1;j<=n;++j){
                if(a[j]-a[j-1] > d)   break;
                while(a[j]-a[l] > d){
                    dsval[mdst[l]] -= mval[l]; ++ l;
                    while(dsval[nowmn] == 0) ++ nowmn;
                }
                mdst[j] = nowmn + 1;
                mval[j] = min(3ll, dsval[nowmn]);
                dsval[mdst[j]] += mval[j];
                if(mval[j] == 2) ++ cnt;
                // cout << i << ' ' << j << endl;
                // for(int k=1;k<=n;++k) cout << '(' << mdst[k] << ',' << mval[k] << ")\n"; 
            }
            for(int j=0;j<=n;++j) mdst[j]=mval[j]=dsval[j]=0;
        }
        cout << cnt << endl;
    }
}