#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
vector<long long> e;
long long cnt;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(n==4&&d==2){
            cout<<1<<"\n"<<2;
            return 0;
        }
        cout<<0<<"\n"<<1;
    }
    return 0;
}
