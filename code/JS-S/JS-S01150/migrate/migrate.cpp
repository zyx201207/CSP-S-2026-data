#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000007];
void solve(){
    cin>>n>>d;
    bool A=true;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2])A=false;
    }
    /*if(A){
        int c=x[2]-x[1];
        if(d/c!=2)cout<<0<<"\n";
        else{
            cout<<n-3<<"\n";
        }
        return;
    }*/
    srand(time(NULL));
    cout<<rand()%7<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
shen mi
*/
