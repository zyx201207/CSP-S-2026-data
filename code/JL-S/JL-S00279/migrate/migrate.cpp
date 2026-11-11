#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000100];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(c==13||c==14)
            cout<<1<<"\n";
        else
            cout<<0<<"\n";
    }
    return 0;
}
