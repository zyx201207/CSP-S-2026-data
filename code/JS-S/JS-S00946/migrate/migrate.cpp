#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+9;
int c;
ll t;
ll n,d;
ll x[maxn];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
