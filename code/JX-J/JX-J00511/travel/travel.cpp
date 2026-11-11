#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
    #feropen('travel.in','r',stdin);
    #feropen('travel.out','w',stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    char cnt[4]={0,0,0,0};
    for(int i=1;i<=s1.size();i++){
    if(c1[i+1]=='01'&&c1[i+1]=='16'&&c2[i+1]=='01'&&c2[i+1]=='16'){
     cout<<"0000";
     break;
    }
    if(c1[i]!=c2[i]){
      cnt[4]={0};
      if(s2[i]!=s1[i]){
       cnt[4]={0};
      }
    }
     if(c1[i]==c2[i]){
       cnt[4]={1,0,0,0};
       if(s2[i]==s1[i]){
       cnt[4]={1,1,0,0};
     }
     }
    }
 //xiaciyiding
    cout<<cnt;
}
