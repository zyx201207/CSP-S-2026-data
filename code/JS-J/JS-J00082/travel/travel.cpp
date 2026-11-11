#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    string p1=s1.substr(0,2),p2=s2.substr(0,2);
    if(c1==c2){
        cout<<1;
        if(p1==p2){
            cout<<1;
            bool x1,x2;
            if(s1.substr(2)=="A"||s1.substr(2)=="B"||s1.substr(2)=="C"){
                x1=true;
            }else{
                x1=false;
            }
            if(s2.substr(2)=="A"||s2.substr(2)=="B"||s2.substr(2)=="C"){
                x2=true;
            }else{
                x2=false;
            }
            if(x1==x2){
                cout<<1;
                if(x1){
                    if(s1.substr(2)=="B"||s2.substr(2)=="B"){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else{
                    cout<<1;
                }
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    
    return 0;
}