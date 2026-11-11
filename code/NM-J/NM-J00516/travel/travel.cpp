#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    char s1[6];
    char s2[6];
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else if(s1[0]==s2[0]&&s1[1]==s2[1]){
        if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='F'||s2[2]=='D'))){
            if(s1[2]=='A'&&s2[2]=='B' || s1[2]=='B'&&s2[2]=='A' || s1[2]=='B'&&s2[2]=='C' || s1[2]=='C'&&s2[2]=='B' || s1[2]=='D'&&s2[2]=='F' || s1[2]=='F'&&s2[2]=='D'){
                cout<<"1111";
            }
            else
                cout<<"1110";
        }
        else
            cout<<"1100";
    }
    else
        cout<<"1000";
    return 0;
}
