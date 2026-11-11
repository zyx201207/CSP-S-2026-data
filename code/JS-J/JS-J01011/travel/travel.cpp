#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        string w1=s1.substr(0,2);
        string w2=s2.substr(0,2);
        if(w1==w2){
            cout<<"1";
            char t1=s1[2];
            char t2=s2[2];
            if((t1>='A'&&t1<='C'&&t2>='A'&&t2<='C')||(t1>='D'&&t1<='E'&&t2>='D'&&t2<='E')){
                cout<<"1";
                if(abs(t1-t2)==1){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                    cout<<"00";
                    return 0;
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }


    return 0;
}
