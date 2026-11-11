#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b){
    return (a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='C')||(a=='D'&&b=='E');
}
bool check2(char a,char b){
    return (a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='E');
}
string c1,s1,c2,s2;
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    cin>>c1>>s1>>c2>>s2;
    int x1=0,x2=0;
    int h1=0,h2=0;
    for(int i=0;i<2;i++){
        x1=x1*10+(c1[i]-'0');
        x2=x2*10+(c2[i]-'0');
        h1=h1*10+(s1[i]-'0');
        h2=h2*10+(s2[i]-'0');
    }
    char hr=s1[2],hx=s2[2];
    if(x1!=x2){
        cout<<"0000";
    }else if(h1!=h2){
        cout<<"1000";
    }else if(!(check(hr,hx)||check(hx,hr))){
        cout<<"1100";
    }else if(!(check2(hr,hx)||check2(hx,hr))){
        cout<<"1110";
    }else{
        cout<<"1111";
    }
    return 0;
}
