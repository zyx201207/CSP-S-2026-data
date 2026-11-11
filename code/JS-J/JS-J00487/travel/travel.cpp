#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,c3,c4;
bool t1,t2;
bool f(char c){
    bool t;
    switch(c){
        case 'A':
        case 'B':
        case 'C':{t=1;break;}
        case 'D':
        case 'F':{t=0;break;}
    }
    return t;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        cout<<"1";
        if(c2.substr(0,2)==c4.substr(0,2)){
            cout<<"1";
            t1=f(c2[2]);t2=f(c4[2]);
            if(t1==t2){
                cout<<"1";
                if(!t1){
                    cout<<"1";
                }
                else if(abs(c2[2]-c4[2])==1){
                    cout<<"1";
                }
                else
                    cout<<"0";
            }
            else
                cout<<"00";
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
    return 0;
}
// Oh, I AC it in 30 minutes(That's too slow!)