#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,x,y;
    cin>>a>>b>>x>>y;
    if(a==x){
        cout<<1;
        if((b[0]==y[0])&&(b[1]==y[1])){
            cout<<1;
            char m=b[2];
            char n=y[2];
            if((m=='A')||(m=='B')||(m=='C')){
                if((n=='A')||(n=='B')||(n=='C')){
                    if(((n=='A')&&(m=='C'))||((m=='A')&&(n=='C'))){
                        cout<<"10";
                        return 0;
                    }else{
                        cout<<"11";
                        return 0;
                    }
                }
            }
            if((n=='E')||(n=='F')){
                if((m=='E')||(m=='F')){
                    cout<<"11";
                    return 0;
                }
            }
            cout<<"00";
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}


