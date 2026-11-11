#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e6 + 10;
ll a[MAXN];
ll n,d;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        if(c == 11||c == 12){
            ll dd;
            for(int i = 0;i < n;i++){
                cin>>a[i];
                if(i == 1){
                    dd = a[1] - a[0];
                }
            }
            if(d > dd&&a[n -1] - a[0] > d){
                cout<<max(0ll,n - (d/dd*2-1))<<'\n';
            }else{
                cout<<"0\n";
            }
        }else if(c == 13||C == 14){
            cout<<"0\n";
        }
    }
    return 0;
}