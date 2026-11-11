#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c>=11&&c<=12){ //sp A
        for(int aaa=0;aaa<t;aaa++){
            int n,d;
            cin>>n>>d;
            int x[n+5];
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            int dis=x[2]-x[1];
            if(dis*2>d){
                cout<<0<<"\n";
                continue;
            }
            else{
                int k=d/dis;
                k=2*k-1;
                cout<<max(0LL,n-k)<<"\n";
            }
        }
    }
    return 0;
}