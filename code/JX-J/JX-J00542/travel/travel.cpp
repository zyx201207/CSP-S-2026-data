#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int num(string s){
    int l;
    for(int i=0;i<2;i++){
        l+=s[i]-'0';
        l*=10;
    }
    return l;
}
int seat_f(string s){
    return s[2]-'A';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int line1=num(s1),seat1=seat_f(s1);
    int line2=num(s2),seat2=seat_f(s2);
    if(c1==c2){
        cout<<1;
        if(line1==line2){
            cout<<1;
            if((seat1/3)==(seat2/3)){
                cout<<1;
                bool flag=0;
                if((seat1>=0)&&(seat1<=2)){
                    if(abs(seat1-seat2)==1)flag=1;
                    else flag=0;
                }
                else flag=1;
                cout<<flag;
            }
            else cout<<"00";
        }
        else{
            cout<<"000";
        }
    }
    else cout<<"0000";
    cout<<endl;
    return 0;
}
