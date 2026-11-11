#include <bits/std c++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        if(c1!="1"and"17" and c2!="1"and"17"){
            cout<<"1";
        }
    }else{
        cout<<"0";
    }
    if(s1[0][1]==s2[0][1]){
    	cout<<"1";
    }else{
    	cout<<"0";
    }
    if(A<=s1[2]<=E and A<=s2[2]<=E){
    	cout<<"1";
    }else{
    	cout<<"0";
    }
    if(s1[2]==s2[2]-1 or s1[2]==s2[2]+1){
        if(s1[2] and s2[2]!="C"and"D" or s1[2] and s2[2]!="A"and"E"){
            cout<<"1";
        }
    }else{
        cout<<"0";
    }
    return 0;
}
