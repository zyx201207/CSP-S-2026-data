#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
        cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
        if(s1[2]=='D'&&s2[2]=='F'){
            cout<<"11";
            return 0;
        }
        if(s1[2]=='F'&&s2[2]=='D'){
            cout<<"11";
            return 0;
        }
        if(s1[2]<='C'&&s2[2]<='C'){
            cout<<"1";
            int h1=s1[2]+1,h2=s2[2]+1;
            if(h1==s2[2]||h2==s1[2])
                cout<<"1";
            else
                cout<<"0";
            return 0;
        }
        cout<<"00";
    }
    else
        cout<<"000";
    return 0;
}
