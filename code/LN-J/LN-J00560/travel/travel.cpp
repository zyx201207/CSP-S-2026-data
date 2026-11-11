#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string c,d,s,t;
    cin>>c>>d>>s>>t;
    if(c==d){
        if(s-t==2||t-s==2){
            if(s=="01D"&&t=="01F"){
                string a=1111;
            }
            if(s=="01A"&&t=="01C"){
                string a=1110;
            }
            else{
                string a=1100;
            }
        }
        if(s-t==1||t-s==1){
            if(s=="01C"&&t=="01D"){
                string a=1100;
            }
            else{
                string a=1111;
            }
        }
        else{
            string a=1000;
        }
    }
    else{
        string a=0000;
    }
    cout<<a;
    return 0;
}
