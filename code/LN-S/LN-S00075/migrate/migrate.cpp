#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,d,x[2000009],T,c;
    vector<int> mp[600];
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<n;i++){
            cin>>x[i];
        }
        if(d>=abs(x[2]-x[1])){
            cout<<n*(n-1)<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}

