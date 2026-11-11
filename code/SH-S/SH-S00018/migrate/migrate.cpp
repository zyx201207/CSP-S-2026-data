#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
typedef long long ll;
int T,c,nn;
ll a[N],d;
ll g[N];
namespace BF{
    int nxt[N],prev[N];
    int stk[N],top = 0;
    int pf[N],gf[N];
    int count(int i,int j){
        return nxt[i]-prev[j]+1;
    }
    ll work(int n){
        if(n <= 3)return 0;
        ll cnt = 0;
        for(int i = n; i >= 1 ; -- i){
            int j = n;
            while(a[j] > a[i]+d)--j;
            nxt[i] = j;
        }
        for(int i = 1 ; i <= n ; ++ i){
            int j = 1;
            while(a[j] < a[i] - d)++j;
            prev[i] = j;
        }
        for(int i = 2; i <= n ; ++ i){
            pf[i] =  nxt[i-1]-max(i,nxt[i-2]);
        }
        for(int i = 2; i <= n ; ++ i){
            gf[i] = (nxt[i] - nxt[i-1]);
        }
        for(int i = 1; i <= n ; ++ i){
            top = 0;
            int j = i;
            stk[++top] = j;
            while(a[j]+d<=a[n]){
                j = nxt[j];
                stk[++top] = j;
            }
            int l = top+1,r = top+1,tot = 0;
            for(int j = 1; j <= top-2 ; ++ j){
                int k = count(stk[j],stk[j+2]);
                if(k == 2)tot++;
                if(k > 2)tot = 2;
                if(tot == 2){
                    r = j+2;
                    if(l == top+1)l = j+2;
                    break;
                }
                if(k == 2 && tot == 1)l = j+2;
            }
            for(int j = 2; j < l ; ++ j)cnt += pf[stk[j]];
            for(int j = l; j < r ; ++ j)cnt += gf[stk[j]];
        }
        return cnt;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> c >> T;
    while(T--){
        cin  >> nn >> d;
        for(int i = 1; i <= nn ; ++ i)cin >> a[i];
        int j = 0;
        ll res = 0;
        for(int i = 1; i < nn ; ++ i){
            g[++j] = a[i];
            if(a[i]+d < a[i+1]){
                res += BF::work(j);
                j = 0;
            }
        }
        g[++j] = a[nn];
        res += BF::work(j);
        cout << res << "\n";
    }
    return 0;
}