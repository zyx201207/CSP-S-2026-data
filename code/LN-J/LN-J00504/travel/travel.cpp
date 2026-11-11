#include<bits/stdc++.h>
using namespace std;
string c1,s1;
string c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int flag=1;
    cin>>c1>>s1;
    cin>>c2>>s2;
    int si1=s1.size();
    int si2=s2.size();
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    for(int i=0;i<s1.size()-1;i++){
        if(s1[i]!=s2[i]){
            flag=0;
        }
    }
    if(flag==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(flag==1){
            if((s1[si1-1]=='A'||s1[si1-1]=='B'||s1[si1-1]=='C')&&(s2[si2-1]=='A'||s2[si2-1]=='B'||s2[si2-1]=='C')){
                cout<<1;
            }
            else if((s1[si1-1]=='D'||s1[si1-1]=='F')&&(s2[si2-1]=='D'||s2[si2-1]=='F')){
                cout<<1;
            }
            else{
                cout<<0;
            }
    }
    else{
        cout<<0;
    }
    if(flag==1){
        if((s1[si1-1]=='A'&&s2[si2-1]=='B')||(s1[si1-1]=='B'&&s2[si2-1]=='A')){
            cout<<1;
        }
        else if((s1[si1-1]=='B'&&s2[si2-1]=='C')||(s1[si1-1]=='C'&&s2[si2-1]=='B')){
            cout<<1;
        }
        else if((s1[si1-1]=='D'&&s2[si2-1]=='F')||(s1[si1-1]=='F'&&s2[si2-1]=='D')){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
    return 0;
}
