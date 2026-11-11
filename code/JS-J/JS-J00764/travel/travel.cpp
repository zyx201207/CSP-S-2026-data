#include<bits/stdc++.h>
using namespace std;
bool b=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s,z,x,y,ans;
    cin>>s>>z>>x>>y;
    if(s==x){
       ans+='1';
    }else{
        ans+='0';
    }
    if(z[1]==y[1]&&z[0]==y[0]){
       ans+='1';
    }else{
       ans+='0';
    }
    char sd=z[2];
    char st=y[2];
    if('A'<=sd&&sd<='C'&&'A'<=st&&st<='C'){
        ans+='1';b=1;
    }
    else if('D'<=sd&&sd<='F'&&'D'<=st&&st<='F'){
        ans+='1';b=1;
    }else{
        ans+='0';
    }
    if(b=1){
       if(sd-st==1||st-sd==1){ans+='1';}
    }
    else{ans+='0';}
    cout<<ans;
    return 0;
}
