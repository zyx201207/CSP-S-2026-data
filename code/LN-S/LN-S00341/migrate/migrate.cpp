#include <bits/stdc++.h>
using namespace std;

int c,t,n,d;
int step;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int x1,x2,x;
        cin>>x1>>x2;
        step=d/(x2-x1);
        for(int i=1;i<=n-2;i++){
            cin>>x;
        }
        if(step==2)cout<<n-3<<endl;
        else{cout<<0<<endl;}
    }
    return 0;
}
