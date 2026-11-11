#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,r1,r2;
    char h1,h2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    r1=10*int(s1[0]-'0')+int(s1[1]-'0');
    r2=10*int(s2[0]-'0')+int(s2[1]-'0');
    h1=s1[2];h2=s2[2];
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    if(r1!=r2){
        cout<<"1000";
        return 0;
    }
    if(((h1=='A'||h1=='B'||h1=='C')&&(h2=='D'||h2=='F'))||((h1=='D'||h1=='F')&&(h2=='A'||h2=='B'||h2=='C'))){
        cout<<"1100";
        return 0;
    }
    if((h1=='A'&&h2=='B')||(h1=='B'&&h2=='A')||(h1=='B'&&h2=='C')||(h1=='C'&&h2=='B')||(h1=='D'&&h2=='F')||(h1=='F'&&h2=='D')){
        cout<<"1111";
        return 0;
    }
    cout<<"1110";
    return 0;
}
