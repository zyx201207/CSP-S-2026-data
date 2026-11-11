#include<iostream>;
using namespace std;
int main(){
    int a,c;
    char b,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
        if(b=!d){
            cout<<"1";
            if(b%10="C"&&d%10="D"||d%10="C"&&b%10="D"){
                cout<<"1";
                if(d%10-b%10==1||b%10-d%10==1){
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
    return 0;
}
