#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int inf=0x3f3f3f3f;
int c,t;
const int N=5011;
bool vis[N][N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>c>>t;
    while(t--){
        ll n,d,a[N];
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        int maxv=2*d-1;
        cout<<maxv/n<<"\n";
    }
    return 0;
}
