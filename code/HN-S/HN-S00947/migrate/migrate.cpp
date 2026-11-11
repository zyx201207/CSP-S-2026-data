#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000010];
int sl[2000010],sr[2000010],lv[2000010],rv[2000010],vx[2000010];
vector<int> lx[2000010];
bitset<2000010> ll,rr;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i = 1;i <= n;++i){
            lv[i] = rv[i] = vx[i] = 0;
            lx[i].clear();
            cin>>a[i];
        }
        for(int i = 1;i <= n;++i){
            vx[i] = 0;
            sr[i] = upper_bound(a + 1,a + 1 + n,a[i] + d) - a - 1;
            sl[i] = lower_bound(a + 1,a + 1 + n,a[i] - d) - a;
        }
        for(int i = 1;i <= n;++i){
            if(sl[i] + 1 >= i)continue;
            lx[sl[i]].push_back(i);
        }
        int num = 0,ans = 0;
        for(int i = 1;i < n;++i){
            if(sr[i] - 1 <= i)continue;
            if(lx[sr[i] - 1].size()){
                ll[i] = true;
                for(int y : lx[sr[i] - 1])
                    rr[y] = true;
                lx[sr[i] - 1].clear();
            }
        }
        int lp = 0;
        for(int i = 1;i <= n;++i){
            lv[i] = i - lp;
            if(ll[i])lp = i;
            if(a[i + 1] - a[i] > d)lp = i;
        }
        int rp = n + 1;
        for(int i = n;i >= 1;--i){
            rv[i] = rp - i;
            if(rr[i])rp = i;
            if(a[i] - a[i - 1] > d)rp = i;
        }
        for(int i = 1;i <= n;++i){
            if(sl[i] + 1 >= i)continue;
            vx[sl[i]] += rv[i];
        }
        for(int i = 1;i <= n;++i){
            if(sr[i] - 1 <= i)continue;
            num += lv[i] * vx[sr[i] - 1];
            if(!vx[sl[i]])continue;
        }
        cout<<num<<'\n';
        for(int i = 1;i <= n;++i)
            vx[i] = ll[i] = rr[i] = sl[i] = sr[i] = 0;
    }
    return 0;
}