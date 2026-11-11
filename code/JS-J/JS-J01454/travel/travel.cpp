#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
        string n1=b.substr(0,2),n2=d.substr(0,2);
        if(n1==n2){
            cout<<"1";
            char n3=b[2],n4=d[2];
            if(((n3=='A'||n3=='B'||n3=='C')&&(n4=='A'||n4=='B'||n4=='C'))||((n3=='D'||n3=='F')&&(n4=='D'||n4=='F'))){
                cout<<"1";
                if(abs(n3-n4)==1){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else{
                cout<<"00";
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
