#include <iostream>
using namespace std;
int main(){
    freopen("travel.in","r","stdin");
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int s1;
    int s2;
    if(c1==c2 && s1+1!=s2 && s1+2!=s2 && s1+3!=s2 && s1+4!=s2){
        cout<<"1000"
        }else if(c1=c2 && s1+1=s2 or s1+2=s2 or s1+3=s2 or s1+4=s2){
            cout<<"1100";
        }else if(c1=c2 && s1+1=s2){
            cout<<"1111";
        }else{
            cout<<"0000";
        }
}
