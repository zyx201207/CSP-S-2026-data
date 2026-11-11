#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int c1,s1;
    string c2,s2;
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1){
        cout<<1;
        if(s2.substr(0,2)==c2.substr(0,2)){
            cout<<1;
            if(((c2.substr(2,1)=="A" || c2.substr(2,1)=="B" || c2.substr(2,1)=="C") &&
               (s2.substr(2,1)=="A" || s2.substr(2,1)=="B" || s2.substr(2,1)=="C")) ||
            ((c2.substr(2,1)=="D" || c2.substr(2,1)=="F") && (s2.substr(2,1)=="D" || s2.substr(2,1)=="F"))){
                cout<<1;
                if(((c2.substr(2,1)=="D" || c2.substr(2,1)=="F") && (s2.substr(2,1)=="D" || s2.substr(2,1)=="F")) ||
                    ((c2.substr(2,1)=="A" || c2.substr(2,1)=="B") && (s2.substr(2,1)=="A" || s2.substr(2,1)=="B")) ||
                   ((c2.substr(2,1)=="B" || c2.substr(2,1)=="C") && (s2.substr(2,1)=="B" || s2.substr(2,1)=="C"))){
                       cout<<1;
                }else{
                    cout<<0;
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
