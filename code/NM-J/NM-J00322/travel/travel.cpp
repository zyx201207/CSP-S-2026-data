#include<bits/stdc++.h>
using namespace std;
int a=0,b=0,c=0,d=0;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a=1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        b=1;
    }
    else{
        cout<<"1000";
        return 0;
    }
    if(63<=s1[2]<=65,63<=s2[2]<=65||66<=s1[2]<=67,66<=s2[2]<=67){
        c=1;
    }
    else{
        cout<<"1100";
        return 0;
    }

    if(s1[2]==63,s2[2]==64||s1[2]==64,s2[2]==65||s1[2]==66,s2[2]==67||s1[2]==66,s2[2]==65||s1[2]==65,s2[2]==64||s1[2]==67,s2[2]==66){
        d=1;
    }
    else{
        cout<<"1110";
        return 0;
    }

    cout<<a<<b<<c<<d;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
