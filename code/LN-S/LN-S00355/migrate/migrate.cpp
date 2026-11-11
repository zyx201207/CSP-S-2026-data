#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;
queue<pair<int,int>> que;
map<pair<int,int>,int> l,inuse;// ==0 没有 >0 第一次 < 0 第二次
vector<pair<int,int>> st[N];
int c,t,n,d,ans,a[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        l.clear();
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            for(int j = i-1;j > 0 && a[i]-a[j] <= d;j--) {
                que.push({j,i});
                l[{j,i}] = 1;
                st[j].push_back({i,1});
                //cerr << i << "->" << j << endl;
            }
        }
        while(!que.empty()){
            auto g = que.front();
            int u = g.first,v = g.second;
            //cerr << u <<" " << v<< endl;
            que.pop();
            if(st[v].empty()) continue;
            for(auto g2 : st[v]){
                int v2 = g2.first,w = g2.second;
                // u -> v2
                //cerr << u << " " << v << " " << l[{u,v}] << " " << v2 << " " << w << " " << l[{u,v2}]<< endl;
                if(abs(l[{u,v2}]) < l[{u,v}]+w && l[{u,v2}] != 0 || inuse[{u,v2}] == 1)continue;
                //cerr << "do" << endl;
                if(l[{u,v2}] == 0) {
                    l[{u,v2}] = l[{u,v}]+w ;
                    que.push({u,v2});
                    st[u].push_back({v2,l[{u,v}]+w});
                }
                else if(l[{u,v2}] > 0 && l[{u,v2}] == l[{u,v}]+w && inuse[{u,v2}] == 0) {
                    ans++;
                    l[{u,v2}] = -l[{u,v2}];
                    que.push({u,v2});
                    st[u].push_back({v2,l[{u,v}]+w});
                }
                else if(l[{u,v2}] < 0 && -l[{u,v2}] == l[{u,v}]+w && inuse[{u,v2}] == 0){
                    ans--;
                    inuse[{u,v2}] = 1;
                }
                //cerr << "-----\n";
            }
        }
        for(int i = 1;i <= n;i++) st[i].clear();
        cout << ans << endl;
        ans = 0;
    }
    //The best ccf , please give me 250+ points in the CSP-S Thank you very much
    //The best ccf , please give me 250+ points in the CSP-S Thank you very much
    //The best ccf , please give me 250+ points in the CSP-S Thank you very much
    //The best ccf , please give me 250+ points in the CSP-S Thank you very much
    return 0;
}
