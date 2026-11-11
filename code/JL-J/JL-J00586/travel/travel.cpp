#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool fl1,fl2,fl3,fl4;
    fl1=fl2=fl3=fl4=1;
    for(int i=0;i<c1.length();i++){
        if(c1[i]!=c2[i]){
            cout<<"0000";
            return 0;
        }
    }
    for(int i=0;i<s1.length()-1;i++){
        if(s1[i]!=s2[i]){
            cout<<"1000";
            return 0;
        }
    }
    for(int i=2;i<s1.length();i++){
        if((s1[i]=='D'&&s2[i]-s1[i]==1)||(s2[i]=='D'&&s1[i]-s2[i]==1)||(s1[i]=='C'&&s1[i]-s2[i]==1)||(s1[i]=='C'&&s1[i]-s2[i]==2)||(s2[i]=='C'&&s2[i]-s1[i]==1)||(s2[i]=='C'&&s2[i]-s1[i]==2)||(s2[i]=='B'&&s2[i]-s1[i]==1)||(s1[i]=='B'&&s1[i]-s2[i]==1)){
             cout<<"111";
        }
        else{
            cout<<"1100";
            return 0;
        }
    }
    for(int i=2;i<s1.length();i++){
        if(s1[i]-s2[i]==1||s2[i]-s1[i]==1){
            cout<<'1';
            return 0;
        }
    }
    cout<<'0';
    return 0;
}
