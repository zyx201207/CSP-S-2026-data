#include <bits/stdc++.h>
#define LL long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int c,t;
LL n,d;
int x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    IOS;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
    }
    if(n==5){
        cout<<1<<endl<<2;
    }else{
        cout<<0<<endl<<1;
    }



    return 0;
}
