#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N],c,t,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //while(1);
    cin>>c>>t;
    while(t--){
            int gc=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];if(i==1)continue;
            if(i==2){
                gc=a[i]-a[i-1];
            }
            if(a[i]-a[i-1]!=gc){
                while(1);
            }
        }
        if(gc>=d){
            cout<<0<<"\n";
            continue;
        }
        else{
            cout<<gc-d<<"\n";
        }
    }
    return 0;
}
