#include <bits/stdc++.h>

using namespace std;
int a[5];
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) a[1]=1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]) a[2]=1;
    else{
        cout<<"1000";
        return 0;
    }
    if(s1[2]=='A'){
        if(s2[2]=='B')cout<<"1111";
        else if(s2[2]=='C') cout<<"1110";
        else cout<<"1100";
    }else if(s1[2]=='B'){
        if(s2[2]=='A'||s2[2]=='C') cout<<"1111";

        else cout<<"1100";
    }
    else if(s1[2]=='D'){
        if(s2[2]=='F') cout<<"1111";
        else cout<<"1100";
    }


    return 0;
}
