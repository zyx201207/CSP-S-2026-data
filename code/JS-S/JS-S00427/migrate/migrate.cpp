#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
vector<pair<int,int>>g[N];
int a[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c;cin>>c;
    if(c!=0) return 0;
    int t;
    cin>>t;
    while(t--){
        int tol,di;
        cin>>tol>>di;
        int pre=0;
        for(int i=1;i<=tol;i++){
            cin>>a[i];
            if(a[i]-pre<=di&&i!=1){
                g[pre].push_back({i,1});
                pre=a[i];
            }
        }
    }
    return 0;
}
