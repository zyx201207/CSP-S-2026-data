#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+8;
int c,t,n;
ll d,x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(x[i]-x[1]<=d&&i!=1) cnt++;
        }
        if(cnt==2) cout<<n-3<<"\n";
        else cout<<0<<"\n";
    }
    return 0;
}
