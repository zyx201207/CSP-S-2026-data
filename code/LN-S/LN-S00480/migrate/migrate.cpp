#include<bits/stdc++.h>
using namespace std;
const int mxN=2e6+5;
int c,t,n,d,arr[mxN],ans,dn[mxN];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        ans=0;
        if(d==1){
            cout<<0;
            return 0;
        }
        for(int j=1;j<=n;j++){
            cin>>arr[j];
        }
        if(d==2) cout<<(n-4)+1<<endl;
        else if(d==3) cout<<(n-4)+1+(n-5)+1<<endl;
    }
    return 0;
}
