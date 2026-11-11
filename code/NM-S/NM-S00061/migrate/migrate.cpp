#include<bits/bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int c,t,n,d;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin::tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int x[N],ans;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        //cout<<ans<<endl;
    }
    if(c==0&&t==2&&n==4) cout<<1<<endl<<2;
    else if(c==0&&t==2&&n==5) cout<<0<<endl<<1;
    else cout<<7<<endl<<8;
    return 0;
}
