#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000005
#define INF 1000000007
#define MOD 998244353
using namespace std;

ll ID,t,n,D,x[MAXN],d[MAXN],ans;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>ID>>t;
    while(t--){
        cin>>n>>D;
        for(int i = 1; i <= n; i++){
            cin>>x[i];
        }
        for(int i = 1,j = 1; i < n; i++){
            while(j < n && x[j + 1] - x[i] <= D)j++;
            d[i] = j;
        }
        ans = 0;
        for(int i = 1; i <= n; i++){
            ll pos = d[i];
            while(pos <= n && d[pos - 1] > pos){
                ans += min(max(d[pos - 1], pos + 1), n) - min(max(d[pos - 2], pos), n);
                pos = d[pos];
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
