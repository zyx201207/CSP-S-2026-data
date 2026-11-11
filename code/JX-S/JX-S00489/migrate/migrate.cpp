#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m;
long long a[2000005],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int x=a[2]-a[1];
        if(m/x>0){
            int k=m/x+1;
            cout<<n-k<<endl;
        }else{
            cout<<0<<endl;
        }
    }
}