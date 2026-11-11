#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int ybh,ebh;
    int yp,ep;
    cin>>c1>>s1>>c2>>s2;
    ybh=int(s1[2]);
    ebh=int(s2[2]);
    if(s1[0]=='0'){
        yp=int(s1[1]-'0');
    }
    else{
        yp=10+int(s1[1]-'0');
    }
    if(s2[0]=='0'){
        ep=int(s2[1]-'0');
    }
    else{
        ep=10+int(s2[1]-'0');
    }
    if(c1==c2){
        cout<<"1";
        if(yp==ep){
            cout<<"1";
            if(ybh>=65 and ybh<=67 and ebh>=65 and ebh<=67){
                cout<<"1";
                if(abs(ybh-ebh)==1)cout<<"1";
                else cout<<"0";
            }
            else if(ybh>=69 and ybh<=70 and ebh>=69 and ebh<=70){
                cout<<"1";
                if(abs(ybh-ebh)==1)cout<<"1";
                else cout<<"0";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
      cout<<"0000";
    }
    return 0;
}
