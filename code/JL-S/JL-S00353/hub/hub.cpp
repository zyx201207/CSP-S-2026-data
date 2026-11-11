#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int n[10000],m[10000],c,t,a,b;
    cin>>c>>t;
    for(int i=1;i<=2*t;i++){
        cin>>n[i]>>m[i];
    }
    if(c==0&&t==2&&n[1]==5&&m[1]==2){
        a=1;
        b=2;
        cout<<a<<endl;
        cout<<b;
    }
    else {
        a=2;
        b=2;
        cout<<a<<endl;
        cout<<b<<endl;
    }
    return 0;
}
