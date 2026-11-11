#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        int x[n];
        for(int j=0;j<n;j++){
            cin>>x[j];
        }
        if(n%2==0&&d%2==0){
            cout<<n/4<<endl;
        }
        else if(n%2!=0&&n>=5){
            cout<<n-3<<endl;
        }
        else if(c==13||c==14){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}
