#include<iostream>
using namespace std;//jideshanin he out
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s11,c2,s21;
    char s12,s22;
    cin>>c1>>s11>>s12>>c2>>s21>>s22;
    /*if(s12=='F'){
        s21='D';
    }
    if(s22=='F'){
        s22='D';
    }
    if(s21=='A'||s21=='B'){
        s21='C';
    }
    if(s22=='A'||s22=='B'){
        s22='C';
    }*/
    //cout<<c1<<" "<<s11<<s12<<" "<<c2<<"  "<<s21<<s22;
    if(c1==c2){
        cout<<1;
        if(s11==s21){
            cout<<1;
            if((s12>='D'&&s22>='D')||(s12<='C'&&s22<='C')){
                cout<<1;
                if(s12+1==s22||s22+1==s12){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<0<<0;
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
