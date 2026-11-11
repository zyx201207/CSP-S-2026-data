#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
   freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        ll a[200006]={0};
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll js=1,sum=0;
        for(int i=0;i<n-1;i++){
            if((a[i+1]-a[i]<d)){
               /* while(a[i+2]-a[i]<d){
                    i+=2;
                }*/
                js++;
            }
            else{
                if(js>=2*d){
                    sum+=js-2*d+1;
                  //sum-=js/3;
                }
                js=1;
            }
        }
        if(js>=2*d){
            sum+=js-2*d+1;
        }
        cout<<sum<<endl;
    }
    return 0;
}
//xin zhong you dang           1
//nian wu yu wei le zhe,sui zhi cheng tian si xun zhang huai min
