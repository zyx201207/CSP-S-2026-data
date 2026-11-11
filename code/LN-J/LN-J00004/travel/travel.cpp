#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a,b;
    int m[4];
    a=(c1[0]-'0')*10+(c1[1]-'0');
    b=(c2[0]-'0')*10+(c2[1]-'0');
    if(a==b){
       m[0]=1;
    }
    else{
       m[0]=0;
       cout<<"0000";
       return 0;
    }
    int x,y;
    x=(s1[0]-'0')*10+(s1[1]-'0');
    y=(s2[0]-'0')*10+(s2[1]-'0');
    if(x==y){
       m[1]=1;
    }
    else{
        m[1]=0;
        cout<<"1000";
        return 0;
    }
    if(s1[2]=='A'&&s2[2]=='B'){
        m[2]=1;
        m[3]=1;
    }
    else{
         if(s1[2]=='B'&&s2[2]=='A'){
              m[2]=1;
              m[3]=1;
         }
         else{
            if(s1[2]=='A'&&s1[2]=='C'){
                m[2]=1;
                m[3]=0;
            }
            else{
                 if(s1[2]=='C'&&s2[2]=='A'){
                     m[2]=1;
                     m[3]=0;
                 }
                 else{
                     if(s1[2]=='B'&&s2[2]=='C'){
                         m[2]=1;
                         m[3]=1;
                     }
                     else{
                         if(s1[2]=='C'&&s2[2]=='B'){
                              m[2]=1;
                              m[3]=1;
                         }
                         else{
                             if(s1[2]=='D'&&s2[2]=='E'){
                                   m[2]=1;
                                   m[3]=1;
                             }
                             else{
                                  if(s1[2]=='E'&&s2[2]=='D'){
                                       m[2]=1;
                                       m[3]=1;
                                  }
                                  else{
                                     m[2]=0;
                                     m[3]=0;
                                  }
                             }
                         }
                     }
                 }
            }

         }
    }
    cout<<m[0]<<m[1]<<m[2]<<m[3];
    return 0;
 }
