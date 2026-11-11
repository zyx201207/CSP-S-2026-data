#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e6+12;
int c,T;
long long n,d,island[N];
long long dis[N];
int main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>island[i];
        cout<<(n+d-1)/d-1<<'\n';
    }
    return 0;
}
