#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
void solve(){
    srand((int)time(NULL));
    int n,m; cin>>n>>m;
    vector<int> arr(n+5);
    for(int i=0;i<m;i++) cout<<rand()%n+1<<" ";
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int T=1; /*cin>>T;*/
    while(T--) solve();
    return 0;
}