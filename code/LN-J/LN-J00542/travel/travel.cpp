#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2;
    string s1,s2;
    cin>>a1>>s1>>a2>>s2;
    if(a1==a2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    int li1=(s1[0]-'0')*10+s1[1]-'0';
    int li2=(s2[0]-'0')*10+s2[1]-'0';
    //cout<<"\n"<<li1<<" "<<li2<<"\n";
    if(li1==li2){
        cout<<2;
    }
    else{
        cout<<"000";
        return 0;
    }
    int roa1=s1[2]-'A';
    int roa2=s2[2]-'A';
    //cout<<"\n"<<roa1<<" "<<roa2<<"\n";
    if(roa1/3==roa2/3){
        cout<<3;
    }
    else{
        cout<<"00";
        return 0;
    }
    //cout<<"\n"<<roa1<<" "<<roa2<<"\n";
    if((roa1-roa2==1)||(roa1-roa2==-1)){
        cout<<4;
    }
    else{
        cout<<0;
    }
    return 0;
}










