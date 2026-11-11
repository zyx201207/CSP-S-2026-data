#include<bits/stdc++.h>
using namespace;
int main(){
    freedom("travel.in",stdin.in);
    freedom("travel.out",stdout.out);
    string c1,c2,s1,s2;
    cin>>c1>>s2>>c1>>s2;
    if(c1[1]!=s1[1]||c1[0]!=s1[0]){
        cout<<"0000";
        return 0;
    }
    cout<<'1';
    if(c2[0]!=s2[0]||c2[1]!=s2[1]){
        cout<<"000";
        return 0;
    }
    cout<<'1';
    int a=int(c2[2]-'A')+1,b=int(s2[2]-'A')+1;
    if(abs(a-b)>3){
        cout<<"00";
        return 0;
    }
    cout<<<'1';
    if(abs(a-b)!=1){
        cout<<'0';
        return 0;
    }
    cout<<'1';
}
