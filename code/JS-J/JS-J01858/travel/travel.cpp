#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    c1=s1=c2=s2=ans="";
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    ans+="1";
    string temp1=s1.substr(0,2),temp2=s2.substr(0,2);
    if(temp1==temp2){
        ans+="1";
        if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
            ans+="1";
            int x1=s1[2]-'A',x2=s2[2]-'A';
            if(abs(x1-x2)==1){
                ans+="1";
            }else{
                ans+="0";
            }
        }else{
            ans+="00";
        }
    }else{
        ans+="000";
    }
    cout<<ans;
    return 0;
}
