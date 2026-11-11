#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,ans="";
    cin>>c1>>s1>>c2>>s2;
    s1[3]=s1[2];
    s2[3]=s2[2];
    if(c1[0]==c2[0]&&c1[1]==c2[1]){//che xiang
        ans+="1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){//tong pai
            ans+="1";
            if((s1[3]<='C'&&s2[3]<='C')||(s1[3]>'C'&&s2[3]>'C')){
                ans+="1";
            }else{
                ans+="0";
            }
        }else{
            ans+="00";
        }
        if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[3]=='A'&&s2[3]=='B'){
            ans+="1";
        }else if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[3]=='B'&&s2[3]=='A'){
            ans+="1";
        }else if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[3]=='B'&&s2[3]=='C'){
            ans+="1";
        }else if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[3]=='C'&&s2[3]=='B'){
            ans+="1";
        }else if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[3]=='D'&&s2[3]=='F'){
            ans+="1";
        }else if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[3]=='F'&&s2[3]=='D'){
            ans+="1";
        }else if(s1[3]==s2[3]&&s1[0]==s2[0]&&abs(s1[1]-s2[1])==1){
            ans+="1";
        }else if(s1[3]==s2[3]&&s1[0]=='1'&&s1[1]=='0'&&s2[0]=='0'&&s2[1]=='9'){
            ans+="1";
        }else if(s1[3]==s2[3]&&s2[0]=='1'&&s2[1]=='0'&&s1[0]=='0'&&s1[1]=='9'){
            ans+="1";
        }else{
            ans+="0";
        }
    }else{
        cout<<"0000";
        return 0;
    }
    cout<<ans;
    return 0;
}
