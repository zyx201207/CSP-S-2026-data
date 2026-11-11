#include <bits/stdc++.h>
using namespace std;
string pai1,pai2;
string c1,s1,c2,s2;
string ce1,ce2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    ce1=s1[3];
    ce2=s2[3];
    pai1[1]=s1[1];
    pai2[1]=s2[1];
    pai1[2]=s1[2];
    pai2[2]=s2[2];

    if(c1==c2) cout<<'1';
    else cout<<'0';

    if(c1==c2&&pai1[1]==pai2[1]&&pai1[2]==pai2[2]) cout<<'1';
    else cout<<'0';

    if(ce1=="D"&&ce2=="F"||ce2=="D"&&ce1=="F") {
        cout<<'1'<<'1';
    }
    else if(ce1=="A"&&ce2=="B"||ce2=="A"&&ce1=="B"){
        cout<<'1'<<'1';
    }
    else if(ce1=="B"&&ce2=="C"||ce2=="B"&&ce1=="C"){
        cout<<'1'<<'1';
    }
    else if(ce1=="A"&&ce2=="C"||ce2=="A"&&ce1=="C"){
        cout<<'1'<<'0';
    }
    else cout<<'0'<<'0';

    return 0;
}
