#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }else cout<<"1";
    string s11="",s22="";
    s11=s11+s1[0]+s1[1];
    s22=s22+s2[0]+s2[1];
    if(s11!=s22){
        cout<<"000";
        return 0;
    }else cout<<"1";
    string sss1="",sss2="";
    sss1=sss1+s1[2];
    sss2=sss2+s2[2];
    if((sss1=="A"||sss1=="B"||sss1=="C")&&(sss2=="D"||sss2=="F")){
        cout<<"00";
        return 0;
    }else if((sss2=="A"||sss2=="B"||sss2=="C")&&(sss1=="D"||sss1=="F")){
        cout<<"00";
        return 0;
    }else cout<<"1";
    if((sss1=="A"&&sss2=="B")||(sss1=="B"&&sss2=="C")||(sss1=="D"&&sss2=="F")) cout<<"1";
    else if((sss2=="A"&&sss1=="B")||(sss2=="B"&&sss1=="C")||(sss2=="D"&&sss1=="F")) cout<<"1";
    else cout<<"0";
    return 0;
}
