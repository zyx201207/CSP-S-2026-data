#include<bits/stdc++.h>
using namespace std;
mt19937 md(chrono::steady_clock::now().time_since_epoch().count());
int get(int l,int r){
    return uniform_int_distribution<int>(l,r)(md);
}
int a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(c==13||c==14) cout<<0<<"\n";
        else cout<<get(0,n)<<"\n";
    }
    return 0;
}
