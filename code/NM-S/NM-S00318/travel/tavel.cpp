#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(int(s1[0])+int(s1[1])==int(s2[0])+int(s2[1])){
        cout<<1;
        if((s1[2]=='A' && s2[2]=='B')||(s1[2]=='A' && s2[2]=='C')||(s1[2]=='B' && s2[2]=='A')||(s1[2]=='B' && s2[2]=='C')||(s1[2]=='C' && s2[2]=='A')||(s1[2]=='C' && s2[2]=='B')||(s1[2]=='D' && s2[2]=='F')||(s1[2]=='F' && s2[2]=='D')){
            cout<<1;
            if((s1[2]=='A' && s2[2]=='B')||(s1[2]=='B' && s2[2]=='A')||(s1[2]=='B' && s2[2]=='C')||(s1[2]=='C' && s2[2]=='B')||(s1[2]=='D' && s2[2]=='F')||(s1[2]=='F' && s2[2]=='D')){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
    return 0;
}
