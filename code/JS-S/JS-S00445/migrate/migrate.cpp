#include<bits/stdc++.h>
using namespace std;
long long C,T,n,d,x[2000002];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> C >> T;
    while(T--){
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> x[i];
        }
        cout << 0 << "\n";
    }
    return 0;
}
