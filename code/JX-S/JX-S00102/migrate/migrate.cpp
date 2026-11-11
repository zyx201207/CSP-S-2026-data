#include<bits/stdc++.h>
using namespace std;
long long n,d,c,t,dd,f=1,m,maxs,a[500005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
        while(t--){
            cin>>n>>d>>a[1]>>a[2];
            dd=a[2]-a[1];
            for(int i=3;i<=n;i++){
                cin>>a[i];
                if(a[i]-a[i-1]!=dd)f=0;
            }
            if(f==1){
                if(dd+1==d){
                    cout<<n-d-1<<"\n";
                }else{
                    cout<<"0\n";
                }
            }else{
                cout<<((n-1)/2*(n-1)/2)<<"\n";
            }
        }


    return 0;
}
