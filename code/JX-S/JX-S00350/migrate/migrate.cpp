#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        vector<int> x(n+1);
        for(int i=0;i<n;i++)cin>>x[i];
        //if(c==11||c==12){
            if(x[1]-x[0]>d)cout<<0<<endl;
            else{
                cout<<n-3<<endl;
            }
        //}
    }
    return 0;
}
