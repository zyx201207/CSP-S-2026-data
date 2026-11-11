#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    string e="",f="";
    e+=b[0];
    e+=b[1];
    f+=d[0];
    f+=d[1];
    int g=int(b[2])-65;
    int h=int(d[2])-65;
    if(a==c){
        if(e==f){
            if((g<=2 && h<=2) || (g>2 && h>2)){
                if(abs(g-h)==1 || (g==3 && h==5) || (g==5 && h==3)) cout<<"1111";
                else cout<<"1110";
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else {
        cout<<"0000";
    }
    return 0;
}
