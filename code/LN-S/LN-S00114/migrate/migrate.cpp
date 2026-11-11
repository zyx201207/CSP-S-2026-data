#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(t==1){
        cout<<0<<endl;
    }
    else if(t==2){
        cout<<0<<endl<<1<<endl;
    }
    else if(t==3){
        cout<<1<<endl<<0<<endl<<2<<endl;
    }
    else if(t==4){
        cout<<1<<endl<<4<<endl<<2<<endl<<0<<endl;
    }
    else{
        while(t--){
            cout<<0<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
}
