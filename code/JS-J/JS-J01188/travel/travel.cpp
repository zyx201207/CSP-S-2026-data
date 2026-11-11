#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    bool a1=0,a2=0,a3=0,a4=0;
    if(c1==c2){
        a1=1;
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            a2=1;
            if((s1[2]=='F' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='F')){
                a3=a4=1;
            }
            else if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C')){
                a3=a4=1;
            }
            else if((s1[2]=='A' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='A')){
                a3=1;
            }
        }
    }
    cout<<a1<<a2<<a3<<a4<<endl;
    return 0;
}
