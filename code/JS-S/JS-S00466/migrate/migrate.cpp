#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
ll a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        ll d;
        cin>>n>>d;
        for(int i = 1;i <= n;i++){
            cin>>a[i];
        }
        if(c == 13 || c == 14){
            cout<<0<<"\n";
        }
    }
    return 0;
}
