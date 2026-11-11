#include<bits/stdc++.h>
using namespace std;
string t1 = "ABC";
string t2 = "DE";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        string p1 = s1.substr(0,2);
        string p2 = s2.substr(0,2);
        if(p1==p2){
            cout<<"1";
            char w1 = s1[2],w2 = s2[2];
            if((t1.find(w1)!=-1)&&(t1.find(w2)!=-1)){
                cout<<"1";
                if(abs(int(w1-w2))==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else if((t2.find(w1)!=-1)&&(t2.find(w2)!=-1)){
                cout<<"1";
                if(abs(int(w1-w2))==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
