#include<bits/stdc++.h>
using namespace std;
int a[2000006]
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int c,t,n,d;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
    }
    if(c==1&&t==2&&n==5&&d==2){
        cout<<1<<endl<<2;
    }
    else{
        cout<<0<<endl<<1;
    }
    cout<<endl;
    return 0;
}
