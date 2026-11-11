#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    string p1 = s1.substr(0,2),p2 = s2.substr(0,2);
    if(p1!=p2){
        cout<<"1000";
        return 0;
    }
    char a = s1[2],b = s2[2];
    if((a == 'C' && b == 'D') || (a == 'D' && b == 'C')){
        cout<<"1100";
        return 0;
    }
    if((a == 'D' && b == 'F') || (a == 'F' && b == 'D')){
        cout<<"1111";
        return 0;
    }
    if(abs(a-b)>1 && (a<='C' && b>'C')||(a>'C' && b<='C')){
        cout<<"1100";
        return 0;
    }else if(!(a<='C' && b>'C')||(a>'C' && b<='C')){
        cout<<"1110";
    }
    if((a<='C' && b>'C')||(a>'C' && b<='C')){
        cout<<"1110";
        return 0;
    } else{
        cout<<"1111";
    }
    return 0;
}
