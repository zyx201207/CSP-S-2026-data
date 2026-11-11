#include<bits/stdc++.h>
using namespace std;
long long j=0;
string s,c,s1,c1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>s1>>c>>c1;
    if(s==c){
        cout<<"1";
    }
    else {
        cout<<"0000";
        return 0;
    }

    if(s1[1]==c1[1]&&s1[2]==c1[2]){
            cout<<"1";
    }
    else {
        cout<<"000";
        return 0;
    }
    if(s1[3]=='A'&&c1[3]=='B') cout<<"11";
    else cout<<"10";


    return 0;
}
