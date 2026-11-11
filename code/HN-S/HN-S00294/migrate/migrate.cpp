#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e6 + 5;
int c, t, n, d, can[N];
vector <pair<int, int> > special;
long long x[N];
long long ans;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--){
        scanf("%d%d", &n, &d);
        for(int i = 1; i <= n; i++)scanf("%lld", &x[i]);
        special.push_back({0, 0});
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++)
                if(x[j] <= x[i] + d)
                    can[i]++;
            if(can[i] != 1)special.push_back({i, can[i]});
        }
/*
        for(auto& i : special){
            cout << i.first << " " << i.second << endl;
        }
*/
        ans = 0;
        for(int i = 1; i <= special.size(); i++){
            if(special[i].second == 0)continue;
            else{
                int pos1, pos2;
                //pos1
                if(i == 1)
                    pos1 = 1;
                else if(special[i-1].second == 0)
                    pos1 = special[i-1].first + 1;
                else
                    pos1 = special[i-1].first + special[i-1].second - 1;

                //pos2
                if(i == special.size())
                    pos2 = n;
                else if(special[i].second > 2)
                    pos2 = min(special[i].first + 2, n);
                else if(special[i+1].second == 0)
                    pos2 = special[i+1].first - 1;
                else
                    pos2 = min(special[i+1].first + 1, n);
                //cout << "ans += " << 1ll * (special[i].first - pos1 + 1) * (pos2 - (special[i].first + 2) + 1) << endl;
                ans += max(0ll, 1ll * (special[i].first - pos1 + 1) * (pos2 - (special[i].first + 2) + 1));
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
