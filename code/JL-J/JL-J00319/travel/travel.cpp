#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,aa,b,bb;
    cin >>a>>aa>>b>>bb;
    string p1=aa.substr(0,2);
    char p11=aa[2];
    string p2=bb.substr(0,2);
    char p22=bb[2];
    if(a!=b){
    cout <<"0000";
    }
    else if(p1!=p2){
        cout <<"1000";
    }
    else if((p11=='C' and p22=='D') or (p11=='D' and p22=='C')){
        cout <<"1100";
    }
    else if(abs(p11-p22)!=1){
        cout<<"1110";
    }
    else{
                cout <<"1111";
    }





    return 0;
}
