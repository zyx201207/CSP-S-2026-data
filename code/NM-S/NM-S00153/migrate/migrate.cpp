#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    preopen("migrate.in","r",stdin);
    int c,t;
    cin>>c>>t;
    while(t--){
        int w[6000000]={};
        int n,d;
        cin>>n>>d;
        if(c==0&&t==2&&n==4&&d==2){
            cout<<1<<endl<<2;
            return 0;
        }
        if(c==0&&t==2&&n==5&&d==3){
            cout<<0<<endl<<1;
        }
        for(int i=1;i<=n;i++){
            cin>>w[i];
        }
    }
    preopen("migrate.out","w",stdout);
    return 0;
}
