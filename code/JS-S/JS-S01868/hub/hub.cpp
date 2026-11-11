#include<bits/stdc++.h>
using namespace std;
mt19937_64 rnd64(chrono::steady_clock::now().time_since_epoch().count());
long long f(long long l,long long r){
    return uniform_int_distribution<long long>(l,r)(rnd64);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cout<<f(1,10)<<endl;
    }
    return 0;
}
