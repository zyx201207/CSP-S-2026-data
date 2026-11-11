#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
void check(){
    if(c1==c2){
        cout<<1;
        string a1="",a2="";
        a1=s1[0]+s1[1],a2=s2[0]+s2[1];
        char asd1=s1[2],asd2=s2[2];
        if(a1==a2){
            cout<<1;
            if((asd1=='C'&&asd2=='D')||(asd1=='D'&&asd2=='C'))  cout<<"00";
            else{
                cout<<1;
                if(asd1+1==asd2||asd2+1==asd1)  cout<<1;
                else  cout<<0;
            }
        }
        else  cout<<"000";
    }
    else  cout<<"0000";
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","W",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    check();
    return 0;
}
