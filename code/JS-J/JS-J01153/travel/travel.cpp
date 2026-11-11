#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool flag=1;
    bool flag1=1;
    bool flag2=0,flag3=0;
    for(int i=0;i<2;i++){
        if(c1[i]-48 == c2[i]-48){
            continue;
        }
        else{
            flag=0;
        }
    }
    if(flag==0)flag1=0;
    if(flag==1){
       for(int i=0;i<2;i++){
        if(s1[i]-48 == s2[i]-48){
            continue;
        }
        else{
            flag1=0;
        }
       }
       if(flag1!=0){
       if(s1[2]=='A' && (s2[2]=='B' || s2[2]=='C')){
           flag2=1;
           if(s1[2]=='A' && s2[2]=='B')flag3=1;
       }
       if(s1[2]=='B' && (s2[2]=='A'|| s2[2]=='C')){
          flag2=1;
          flag3=1;
       }
       if(s1[2]=='C' && (s2[2]=='A' || s2[2]=='B')){
          flag2=1;
          if(s1[2]=='C' && s2[2]=='B')flag3=1;
       }
       if(s1[2]=='D'&&s2[2]=='F' ||  s1[2]=='F'&&s2[2]=='D'){
           flag2=1;
          flag3=1;
       }
     }
    }

  cout<<flag<<flag1<<flag2<<flag3;
    return 0;
}

