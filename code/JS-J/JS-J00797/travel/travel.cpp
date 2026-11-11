#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1!=c2){
        cout<<"0000";
    }
    else {
        cout<<1;
        if (s1[0]+s1[1]!=s2[0]+s2[1]){
            cout<<"000";
        }
        else {
            cout<<1;
            char x=s1[2];
            char y=s2[2];
            if(x>='A' && x<='C' && y>='A' && y<='C'){
                cout<<"1";
                if (x+1==y||y+1==x){
                    cout<<"1";
                }
                else {
                    cout<<"0";
                }
            }
            else {
                if(x>='D' && x<='F' && y>='D' && y<='F'){
                    cout<<"11";
                }
                else {
                    cout<<"00";
                }
            }
        }
    }
    return 0;
}
//JS-J00797
