#include <bits/stdc++.h>
#define ll long long
#define N 500100
using namespace std;
ll f[N],delta[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    sort(f+1,f+n+1);
    for(int i=2;i<=n;i++){
        delta[i]=delta[i-1]+(i-1)*(f[i]-f[i-1]);
    }
    cout<<upper_bound(delta+1,delta+n+1,m)-delta-1;
    return 0;
}
