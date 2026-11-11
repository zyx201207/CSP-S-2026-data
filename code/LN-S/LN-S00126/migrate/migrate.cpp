#include<bits/stdc++.h>
using namespace std;
const int mxN=1e6+5;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n;
        long long int d,x[mxN];
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[i];
        }
        cout<<i<<endl;
    }
    return 0;
}
