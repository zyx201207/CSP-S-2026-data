#include <bits/stdc++.h>
using namespace std;
const int N=2000010;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int xn[N];
        for(int i=1;i<=n;i++){
            cin>>xn[i];
        }
        if((xn[2]-xn[1])*2>d)cout<<0;
        int j=0;
        for(j=n;j>=2;j--){
            if(xn[j]<2*d){
                break;
            }
        }
        if(j==0) cout<<0;
        else cout<<n-j+1<<endl;
    }
    return 0;
}
