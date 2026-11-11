#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
int a[N];
long long c,t,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(a[2]-a[1]>d || n==1){
            cout<<0<<endl;
        }else{
            cout<<n-d-1<<endl;
        }
    }
    return 0;
}
