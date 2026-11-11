#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream cin("travel.in");
    ofstream cout("travel.out");
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int rc,xc;
    rc=stoi(c1);
    xc=stoi(c2);
    if(rc!=xc){
        cout<<"0000";
    }else{
        cout<<"1";
        int rl,xl;
        rl=stoi(s1.substr(0,2));
        xl=stoi(s2.substr(0,2));
        if(rl!=xl){
            cout<<"000";
        }else{
            cout<<"1";
            int rp,xp;
            bool b1=0,b2=0;
            rp=s1[2];
            xp=s2[2];
            if(rp<68)b1=1;
            if(xp<68)b2=1;
            if(b1!=b2){
                cout<<"00";
            }else{
                cout<<"1";
                if(abs(rp-xp)==1){
                    cout<<"1";

                }else{
                    cout<<"0";
                }
            }
            //cout<<"\n"<<rp<<" "<<xp;
        }
    }
    return 0;
}
