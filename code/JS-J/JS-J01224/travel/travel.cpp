#include <bits/stdc++.h>
using namespace std;
string a1,s1,a2,s2;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>s1>>a2>>s2;
    if(a1==a2){
        cout<<1;
        if(s1.substr(0,2)==s2.substr(0,2)){
            cout<<1;
            if(s1.substr(2,1)=="A"){
                if(s2.substr(2,1)=="B"||s2.substr(2,1)=="C"){
                    cout<<1;
                    if(s2.substr(2,1)=="B")cout<<1;
                    else cout<<0;
                }
                else cout<<"00";
            }
            else if(s1.substr(2,1)=="B"){
                if(s2.substr(2,1)=="A"||s2.substr(2,1)=="C"){
                    cout<<1;
                    if(s2.substr(2,1)=="A"||s2.substr(2,1)=="C")cout<<1;
                    else cout<<0;
                }
                else cout<<"00";
            }
            else if(s1.substr(2,1)=="C"){
                if(s2.substr(2,1)=="A"||s2.substr(2,1)=="B"){
                    cout<<1;
                    if(s2.substr(2,1)=="B")cout<<1;
                    else cout<<0;
                }
                else cout<<"00";
            }
            else if(s1.substr(2,1)=="D"){
                if(s2.substr(2,1)=="F"){
                    cout<<1;
                    if(s2.substr(2,1)=="F")cout<<1;
                    else cout<<0;
                }
                else cout<<"00";
            }
            else if(s1.substr(2,1)=="F"){
                if(s2.substr(2,1)=="D"){
                    cout<<1;
                    if(s2.substr(2,1)=="D")cout<<1;
                    else cout<<0;
                }
                else cout<<"00";
            }
        }else cout<<"000";
    }
    else cout<<"0000";

    return 0;
}
