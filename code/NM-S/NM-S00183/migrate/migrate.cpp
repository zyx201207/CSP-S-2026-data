
#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000011],o=0;
int main(){
    cin>>c>>t>>n>>d;
    for(int i=1;i<=t;++i){
        for(int j=1;j<=n;++j){
            cin>>x[i];
        }
        for(int j=1;j<=n;++j){
            if(n>=j+2*d-1){
                ++o;
            }
        }
        cout<<o;
    }

    return 0;
}
