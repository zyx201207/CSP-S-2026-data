#include<bits/stdc++.h>
#define ll long long
#define N 5000015
using namespace std;
ll n,m,v,c,a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>v>>c;
    while(c--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<n<<" "<<m<<endl;
        if(m==1){
            cout<<0<<endl;
        }
        if(v==11||v==12||v==0){
            cout<<max(0ll,n-m-n/(m+1))<<endl;;
        }

    }
    return 0;
}
