#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    char s1[4],s2[4];
    cin>>c1;
    for(int i=0;i<3;i++){
        cin>>s1[i];
    }
    cin>>c2;
    for(int i=0;i<3;i++){
        cin>>s2[i];
    }
    if(c1!=c2){
        cout<<"0000";
    }
    else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"1000";
    }
    else if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')){
        cout<<"1100";
    }
    else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')){
        cout<<"1100";
    }
    else if((s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C')){
        cout<<"1110";
    }else{
        cout<<"1111";
    }
    return 0;
}
