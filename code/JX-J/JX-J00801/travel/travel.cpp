#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<'1';
    }else{
        cout<<"0000";
        return 0;
    }
    string a="",b="";
    a+=s2[0];
    a+=s2[1];
    b+=s4[0];
    b+=s4[1];
    if(a==b){
        cout<<'1';
    }else{
        cout<<"000";
        return 0;
    }
    char cc=s2[2];
    char dd=s4[2];
    bool fl=false;
    if(cc=='A'){
        if(dd=='B'||dd=='C'){
            fl=true;
        }
    }
    if(cc=='B'){
        if(dd=='A'||dd=='C'){
            fl=true;
        }
    }
    if(cc=='C'){
        if(dd=='B'||dd=='A'){
            fl=true;
        }
    }
    if(cc=='D'){
        if(dd=='F'){
            fl=true;
        }
    }
    if(cc=='F'){
        if(dd=='D'){
            fl=true;
        }
    }
    if(fl==true){
        cout<<'1';
    }else{
        cout<<"00";
        return 0;
    }
    fl=false;
    if(cc=='D'){
        if(dd=='F'){
            fl=true;
        }
    }
    if(cc=='F'){
        if(dd=='D'){
            fl=true;
        }
    }
    if(cc=='A'){
        if(dd=='B'){
            fl=true;
        }
    }
    if(cc=='B'){
        if(dd=='A'){
            fl=true;
        }
    }
    if(cc=='B'){
        if(dd=='C'){
            fl=true;
        }
    }
    if(cc=='C'){
        if(dd=='B'){
            fl=true;
        }
    }
    if(fl==true){
        cout<<'1';
        return 0;
    }else{
        cout<<'0';
        return 0;
    }
    return 0;
}
