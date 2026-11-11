#include<bits/stdc++.h>
using namespace std;
bool pan(char a,char b){
     if(a>='D'&&b>='D')return true;
     if(a<'D'&&b<'D')return true;
     return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int tmp1=0,tmp2=0;
    for(int i=0;i<c1.size();i++){
        tmp1=tmp1*10+int(c1[i]-'0');
    }
    for(int i=0;i<c2.size();i++){
        tmp2=tmp2*10+int(c2[i]-'0');
    }
    if(tmp1==tmp2)cout<<"1";
    else{
         cout<<"0000";
         return 0;
    }
    int sum1=0,sum2=0;
    char seat1,seat2;
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='0'&&s1[i]<='9')sum1=sum1*10+int(s1[i]-'0');
        else seat1=s1[i];
    }
    for(int i=0;i<s2.size();i++){
        if(s2[i]>='0'&&s2[i]<='9')sum2=sum2*10+int(s2[i]-'0');
        else seat2=s2[i];
    }
    if(sum1==sum2){
       cout<<"1";
    }else{
          cout<<"000";
          return 0;
    }
    if(pan(seat1,seat2)){
       cout<<"1";
    }else{
          cout<<"00";
          return 0;
    }
    if(abs(int(seat1-seat2))==1)cout<<"1";
    else cout<<"0";
    return 0;
}
