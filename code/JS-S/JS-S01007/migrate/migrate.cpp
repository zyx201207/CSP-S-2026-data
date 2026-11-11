#include<bits/stdc++.h>
using namespace std;
long long c,t,n,n_,f,d,x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(x,0,sizeof(x));
        cin>>n_>>d;
        n=n_;
        while(n_--){
            cin>>x[n-n_];
        }
        //f++;
        //if(f) cout<<n<<" "<<d<<" "<<x[1]-x[2]<<" ";
        if(abs(x[2]-x[1])*2>d){
            cout<<0<<endl;
        }
        else{
            f=n-2*d/abs(x[2]-x[1])+1;
            if(f>0) cout<<f<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
