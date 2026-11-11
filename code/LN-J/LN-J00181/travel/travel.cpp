#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b1,a2,b2;
    bool o=true;
    cin>>a1>>b1>>a2>>b2;
    if(a1==a2){
        cout<<"1";
    }
    else{
        cout<<"0000";
        o=false;
    }
    if(b1[1]==b2[1]&&b1[0]==b2[0]&&o){
        cout<<"1";
    }
    else if(o){
        cout<<"000";
        o=false;
    }
    if((b1[2]=='D'||b1[2]=='F')&&(b2[2]=='D'||b2[2]=='F')&&o){
        cout<<"11";
        o=false;
    }
    else if((b1[2]=='A'||b1[2]=='B'||b1[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')&&o){
        cout<<"1";
        if(b1[2]+1==b2[2]||b1[2]-1==b2[2]){
            cout<<1;
            o=false;
        }
        else if(o){
            cout<<0;
            o=false;
        }
    }
    else if(o){
        cout<<"00";
        o=false;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
