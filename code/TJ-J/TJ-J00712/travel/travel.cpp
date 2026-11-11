#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int o,i;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>S2;

    if(c1==c2){
        i=1;
        cout << "1";
    }
    for(inti=0;i<2;i++){
        if(s1[i]==s2[i]&& i=1){
            o=1;
        }
        else {
            break;
        }
    }
    if(o==1){
        cout << "1";
    }
    else{
        cout <<"0";
    }
    if('A'<=s1[3]<='C'&&'A'<=s2[3]<='C')||('D'<=s1[3]<='E'&&'D'<=s2[3]<='E'&&0==1){
        cout << "1";
    }
    else{
        cout << "0";
    }
    if(s1[3]=='A'&&s2[3]=='B')||(s1[3]=='B'&&s2[3]=='A')||(s1[3]=='B'&&s2[3]=='C')||(s1[3]=='C'&&s2[3]=='B')||(s1[3]=='D'&&s2[3]=='E')||(s1[3]==]'E'&&s2[3]=='D'){
        cout << "1";
    }
    else {
        cout << "0";
    }
    return 0;
}

