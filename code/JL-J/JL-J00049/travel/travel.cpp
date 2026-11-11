#include<iostream>
using namespace std;
int main(){
    int a,s;
    string d,f;
    cin>>a>>s;
    cin>>d>>f;
    if(d==f){
        cout<<"1";
        if(a/100==s/100){
            cout<<"1";
            if(a%100<=67&&s%100<=67||a%100>=68&&s%100>=6){

                cout<<"1";
                 if(a+1==s||a-1==s){

                    cout<<"1";
    }
                else{
                    cout<<"0";
                }
                else{
                    cout<<"00";
                }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }


    }

    }

}
