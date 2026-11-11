#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n,m;
int a[N];
int ret[N],ans[N],q[N],hh,tt;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++ ){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++ ){
        hh = 1,tt = 0;
        memset(q,0,sizeof q);
        for(int j = i;j <= n;j ++ ){
            if(!ret[a[j]]){
                    q[++tt] = a[j];
                    ret[a[j]] = tt;
            }
            else{
                tt = ret[a[j]];
                q[++tt] = a[j];
            }
        }
        memset(ret,0,sizeof ret);
        for(int i = hh;i < tt;i ++ ){
            ans[q[i]] ++;
        }
    }
    for(int i = 1;i <= m;i ++ ){
        cout << ans[i] << " ";
    }
    cout << endl;
   return 0;
}
