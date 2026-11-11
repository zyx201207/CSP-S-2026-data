#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string  a,b;
    a=s1.substr(0,2);
    b=s2.substr(0,2);
    string c,d;
    c=s1.substr(2,1);
    d=s2.substr(2,1);
    if(c1==c2){
        cout<<"1";
        if(a==b){
            cout<<"1";
            if(c>="A"&&c<="C"&&d>="A"&&d<="C"||c>="D"&&c<="F"&&d>="D"&&d<="F"){
                cout<<"1";
                if(c=="A"&&d=="B"||c=="B"&&d=="C"||d=="A"&&c=="B"||d=="B"&&c=="C"||c=="E"&&d=="F"||d=="E"&&c=="F"){
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
