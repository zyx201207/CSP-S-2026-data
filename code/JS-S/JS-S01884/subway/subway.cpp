#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int w[N],c,n,m,d,q,k[N],a,t;
vector<int> G[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i ++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j ++){
            cin >> a >> t;
            G[a].push_back(i);
        }
    }
    while(q --){
        int x,y;
        cin >> x >> y;
    }
    return 0;
}
