#include<bits/stdc++.h>
using namespace std;
#define maxn 2000006
int C,T,n,d,x[maxn];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>C>>T;
    for(int j=1;j<=T;j++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        cout<<j<<endl;
    }
    return 0;
}
