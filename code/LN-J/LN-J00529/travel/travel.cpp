#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen(pow.in,"r",stdin);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"1000";
        return 0;
    }
    else if(!((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))){
        cout<<"1100";
        return 0;
    }
    else if(!((s2[2]==s1[2]-1)||(s1[2]==s2[2]-1))){
        cout<<"1110";
        return 0;
    }
    else{
        cout<<"1111";
    }
    return 0;
    freopen(pow.out,"w",stdout);
}
