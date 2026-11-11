#include<bits/stdc++.h>
using namespace std;
int s[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d,x;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x;
        }
        if(s[2]-s[1]==s[3]-s[2]){
            cout<<n-d-d+1<<endl;
        }
        else{
            cout<<t;
        }
    }
    return 0;
}
