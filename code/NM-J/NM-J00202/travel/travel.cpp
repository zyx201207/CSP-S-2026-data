#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    int s=0;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
    }

    else{
        s+=1000;
        if(b.substr(0,2)!=d.substr(0,2)){
            cout<<s;
        }
        else{
            s+=100;
            if(((b.substr(2)=="D"&&d.substr(2)!="F")||(b.substr(2)=="F"&&d.substr(2)!="D"))||((d.substr(2)=="D"&&b.substr(2)!="F")||(d.substr(2)=="F"&&b.substr(2)!="D"))){
                cout<<s;
            }
            else{
                s+=10;
                if((b.substr(2)=="C"&&d.substr(2)=="A")||(b.substr(2)=="A"&&d.substr(2)=="C")){
                    cout<<s;
                }
                else{
                    cout<<"1111";
                }
            }
        }
    }
    return 0;
}
