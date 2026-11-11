#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1;
    cin>>c1>>s1;
    string c2,s2;
    cin>>c2>>s2;
    int len=c1.size();
    for(int i=0;i<len;i++){
        if(c1[i]!=c2[i]){
            cout<<"0000";
            return 0;
        }
    }
    for(int i=0;i<=1;i++){
            if(s1[i]!=s2[i]){
                cout<<"1000";
                return 0;
            }
    }
    if( ((s1[2]=='A'&&s2[2]=='B') || (s1[2]=='B'&&s2[2]=='A')) || ((s1[2]=='B'&&s2[2]=='C') || (s1[2]=='C'&&s2[2]=='B')) || ((s1[2]=='D'&&s2[2]=='F') || (s1[2]=='F'&&s2[2]=='D') ) ){
        cout<<"1111";
        return 0;
    }
    else if((s1[2]=='A'&&s2[2]=='C') || (s1[2]=='C'&&s2[2]=='A')){
        cout<<"1110";
        return 0;
    }
    else{
        cout<<"1100";
        return 0;
    }
    return 0;
}

