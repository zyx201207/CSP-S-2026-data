#include<iostream>
#define int long long
using namespace std;
const int N=2000006;
int a[N];
int c,t;
int n,d;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            
        }
        int f=a[2]-a[1];
        if(d<f){
            cout<<"0"<<endl;
        }else{
            cout<<max(0LL,n+1-(d/f*2))<<endl;
        }
    }
}