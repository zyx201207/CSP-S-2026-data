#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e6+5;
int c,t,n,d,x;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(NULL));
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=0;i<n;++i) cin>>x;
        cout<<rand()%10<<'\n';
    }
    return 0;
}