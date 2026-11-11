#include<bits/stdc++.h>
using namespace std;
string s,c1,c2,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        s=s+'1';
    }
    else {
            s=s+"0000";
            cout<<s;
            return 0;
    }
    if(s1[1]==s2[1]&&s1[0]==s2[0]){
        s=s+'1';
    }
    else {
            s=s+"000";
            cout<<s;
            return 0;
    }
    if(s1[2]>=65&&s1[2]<=67&&s2[2]>=65&&s2[2]<=67||s1[2]>=68&&s1[2]<=69&&s2[2]>=67&&s2[2]<=69){
        s=s+'1';
    }
    else{
        s=s+"00";
        cout<<s;
        return 0;
    }
    if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
        s=s+'1';
    }
    else{
        s=s+'0';
    }
    cout<<s;
    return 0;
}
