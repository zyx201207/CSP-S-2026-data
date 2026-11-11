#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    char w1,w2,m1,m2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            w1=s1[2];
            w2=s2[2];
            if(w1=='D') w1='F';
            if(w2=='D') w2='F';
            if(w1=='F') w1='G';
            if(w2=='F') w2='G';
            m1=max(w1,w2);
            m2=min(w1,w2);
            if(m1-m2<3){
                cout<<"1";
                if(m1-m2==1) cout<<"1";
                else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
