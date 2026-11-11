#include <iostream>
#include <vector>
using namespace std;
struct node{
    int ti;
    int ai;
};
vector<vector<node> > stn;
int wi[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
        cin >> wi[i];
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;i <= k;i++){
            int a,t;
            cin >> a >> t;
            stn[i].push_back({t,a});
        }

    }
    return 0;
}
