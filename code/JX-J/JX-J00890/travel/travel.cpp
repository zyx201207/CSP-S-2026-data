#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<1;
    }else{
        f=1;
        cout<<0;
    }
    if(f==1){
        cout<<"000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }else{
        f=1;
        cout<<0;
    }
    if(f==1){
        cout<<"00";
        return 0;
    }
    if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>='D'&&s2[2]>='D')){
        cout<<1;
    }else{
        f=1;
        cout<<0;
    }
    if(f==1){
        cout<<"0";
        return 0;
    }
    int a1=int(s1[2]-'A');
    int a2=int(s2[2]-'A');
    if(fabs(a1-a2)==1||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
