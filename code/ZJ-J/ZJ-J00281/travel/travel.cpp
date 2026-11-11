#include "bits/stdc++.h"
using namespace std;
bool q1,q2,q3,q4;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
//    cout<<c1<<"　"<<c2;
    if(c1==c2){
        q1=1;
        if(s1[0]==s2[0] and s1[1]==s2[1]){
            q2=2;
            if((s1[2]<'D' and s2[2]<'D')or(s1[2]>'D' and s2[2]>'D')){
                q3=1;
                //ABC座
                if(s1[2]<'D' and s2[2]<'D'){
                    //AB、BC、BA、CB
                    if((s1[2]=='A' and s2[2]=='B') or (s1[2]=='B' and s2[2]=='C') or (s1[2]=='B' and s2[2]=='A') or (s1[2]=='C' and s2[2]=='B')){
                        q4=1;
                    }
                }
                //DF座
                if(s1[2]>'D' and s2[2]>'D'){
                    
                    //FD、DF
                    if((s1[2]=='D' and s2[2]=='F') or (s1[2]=='F' and s2[2]=='D')){
                        q4=1;
                    }
                }
            }
        }
    }
    if(q1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(q2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(q3){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(q4){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}