#include <bits/stdc++.h>

using namespace std;
int tonumber(char a){
    if(a>='0' && a<='9'){
        return a-'0';
    }
    return false;
}
bool xl(char a,char b){
    if(a+1==b || a-1==b){
        return true;
    }
    return false;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int c1,c2;
    string _s1,_s2;
    cin>>c1>>_s1>>c2>>_s2;
    int s1=tonumber(_s1[0])*10+tonumber(_s1[1]),s2=tonumber(_s2[0])*10+tonumber(_s2[1]);

    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if((c1==c2) && s1==s2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(((c1==c2) && s1==s2) && (((_s1[2]=='A' || _s1[2]=='B' || _s1[2]=='C')&&(_s2[2]=='A' || _s2[2]=='B' || _s2[2]=='C'))||((_s1[2]=='D' || _s1[2]=='F')&&(_s2[2]=='D' || _s2[2]=='F')))){
        cout<<1;
    }else{
        cout<<0;
    }
    if((((c1==c2) && s1==s2) && (((_s1[2]=='A' || _s1[2]=='B' || _s1[2]=='C')&&(_s2[2]=='A' || _s2[2]=='B' || _s2[2]=='C'))||((_s1[2]=='D' || _s1[2]=='F')&&(_s2[2]=='D' || _s2[2]=='F')))) && xl(_s1[2],_s2[2])){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
