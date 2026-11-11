#include <bits/stdc++.h>
using namespace std;
string a,b;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    int sum=0,cnt=0;
    sum=sum*10+s1[0]-'0';
    sum=sum*10+s1[1]-'0';
    cnt=cnt*10+s2[0]-'0';
    cnt=cnt*10+s2[1]-'0';
    if(cnt!=sum){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(s1[2]<='C'&&s2[2]<='C'){
        cout<<1;
        if(abs(s1[2]-s2[2])==1){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if(s1[2]>'C'&&s2[2]>'C'){
        cout<<1;
        if(abs(s1[2]-s2[2])==1){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<"00";
    }
    return 0;
}
