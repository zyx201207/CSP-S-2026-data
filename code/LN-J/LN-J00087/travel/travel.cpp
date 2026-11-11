#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
int main(){

     freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
cin>>a>>b>>e>>c>>d>>f;
if(a==c){
    cout<<'1';
    if(b==d){
        cout<<'1';
        if(e!='C'||f!='D'){
            cout<<'1';
            if(abs((e-'A')-(f-'A'))==1){
                cout<<'1';
            }else{
            cout<<'0';}
        }else{
        cout<<"00";
        }

    }else{
        cout<<"000";
    }

}
else{
   cout<<"0000";
}

}
