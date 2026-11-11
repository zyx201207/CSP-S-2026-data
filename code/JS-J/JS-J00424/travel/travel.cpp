#include<bits/stdc++.h>
using namespace std;
bool ABC_or_DE(char c){
    if((c=='A')||(c=='B')||(c=='C')){
        return true;
    }
    return false;
}
bool A(char c){
    if(c=='A'){
        return true;
    }
    return false;
}
bool B(char c){
    if(c=='B'){
        return true;
    }
    return false;
}
bool C(char c){
    if(c=='C'){
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if((s1[0]==s2[0])&&(s1[1]==s2[1])){
            cout<<1;
            if(ABC_or_DE(s1[2])==ABC_or_DE(s2[2])){
                cout<<1;
                if((!ABC_or_DE(s1[2]))&&(!ABC_or_DE(s2[2])))
                {
                    cout<<1;
                    return 0;
                }
                else{
                    char x=s1[2],y=s2[2];
                    if((A(x)&&B(y))||(A(y)&&B(x))||(B(x)&&C(y))||(B(y)&&C(x))){
                        cout<<1;
                        return 0;
                    }
                    else{
                        cout<<0;
                        return 0;
                    }
                }
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
}
