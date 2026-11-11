#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2114514;

ll a[maxn],b[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin >> c >> t;
    while(t--){

    int n,d;cin >> n >> d;
    ll sum = 0;
    for(ll i = 1,o1 = 0,o2 = 0,o3 = 0,o4 = 0;i <= n;i++,o1 = o2){
        cin >> o2;
        if(i == 1){
            o1 = o2;
        }else{
        if(o2-o1==d){
            o4++;
        }
        if(o4==1){
            sum++;
        }
        }
    }
    cout << sum << '\n';

    }
    return 0;
}
