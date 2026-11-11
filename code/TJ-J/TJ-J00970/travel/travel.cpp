#include <bits/stdc++.h>
using namespace std;

int a,s,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string aq,sw;
    cin>>a>>aq>>s>>sw;
    if(a==s){
        cout<<"1";
        if(aq[1]==sw[1] && aq[0]==sw[0]){
            cout<<"1";
            cout<<"11"; 


        }
        else{
            cout<<"000";
        }



    }
    else{
        cout<<"0000";
    }




    return 0;
}
