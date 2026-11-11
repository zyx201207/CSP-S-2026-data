#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int flag;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    flag=1;
    cin>>s1>>c1>>s2>>c2;
    if(s1!=s2){
     cout<<"0000";
     flag=0;
    }
    else if(s1==s2){
        cout<<"1";
        if(c1[0]!=c2[0]||c1[1]!=c2[1]||flag==0){
            cout<<"000";
            flag=0;
        }
        else if(c1[0]==c2[0]&&c1[1]==c2[1]&&flag!=0){
            cout<<"1";
            if((c1[2]<='C'&&c2[2]>='D')||(c1[2]>='D'&&c2[2]<='C')||flag==0)
            {
               cout<<"00";
               flag=0;
            }
            else if((c1[2]<='C'&&c2[2]<='C')||(c1[2]>='D'&&c2[2]>='D')&&flag!=0){
                 cout<<"1";
                 if(abs(c1[2]-c2[2])!=1||flag==0){
                    cout<<"0";
                 }
                 else if(abs(c1[2]-c2[2])==1&&flag!=0){
                    cout<<"1";
                 }
              }
        }
    }
    return 0;
}
