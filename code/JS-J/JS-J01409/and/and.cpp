#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int x[5],y[5],z[10],w[20],q[35];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxx = 0,yu;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        maxx = max(maxx,a[i]);
        if(i == 1) yu = a[i];
        else yu = yu&a[i];
    }
    if(m == 1) cout<<maxx;
    else if(m == 2 && n <= 2000){
        int maxn = 0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n && j!= i;++j){
                    if((a[i] & a[j]) > maxn){
                        maxn = a[i]&a[j];
                     }
             }
        }
        cout<<maxn;
    }
    else if(m == n) cout<<yu;
   else{
        int ans = 0,cnt = 0;
        for(int u=1;u<=32;++u){
            map<int,int> mp,mp2;
            int k = (1<<u);
            cnt = 0;
            for(int i=1;i<=n;++i){
                mp[a[i]%k]++;
                mp2[a[i]/k]++;
                if(mp[a[i]%k] >= m){
                    ans = max(ans,a[i]%k);
                    cnt = max(cnt,a[i]%k);
                }
                if(mp2[a[i]/k] >= m){
                    ans = max(ans,a[i]/k*k);
                    cnt = max(cnt,a[i]/k*k);
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
//9:15 kai xie(50 fen)
//9:23 xie wan(50 fen dp)
//9:27 WA le
