#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int c,t,n,d,x[N+5],maxx;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        maxx=0;
        for(int i=1;i<=n;i++){
            cin >> x[i];
            if(i!=1){
                maxx=max(maxx,x[i]-x[i-1]);
            }
        }
        if(d<maxx){
            cout << 0 << "\n";
            continue;
        }
        int t=d/(x[2]-x[1]);
        //cout << t << " ";
        if(t==1 || n+1<=2*t){
            cout << 0 << "\n";
            continue;
        }
        cout << n+1-2*t << "\n";
    }
    return 0;
}