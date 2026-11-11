#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d,k,y;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        int a[n];
        for(int j=1;j<=n;j++){
            cin>>a[i];
        }
            if(c=1){
        cout<<n;
    }
    else{
        k=a[2]-a[1];
        y=d/k;
        if(n%y==0){
            cout<<n/y;
        }
        else{
            cout<<n/y+1;
        }
    }
    }
return 0;
}

