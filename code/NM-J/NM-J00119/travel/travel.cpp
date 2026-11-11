#include<bits/stdc++.h>
using namespace std;

bool sc(char n,char m){
    if(n=='A' || n=='B' || n=='C'){
        if(m=='A' || m=='B' || m=='C') return true;
    }
    else{
        if(m=='D' || m=='F') return true;
    }
    return false;
}
bool ling(char n,char m){
    if(n=='A' && m=='B') return true;
    else if(n=='B' && m=='A') return true;
    else if(n=='B' && m=='C') return true;
    else if(n=='C' && m=='B') return true;
    else if(n=='D' || m=='F') return true;
    else if(n=='F' && m=='D') return true;
    return false;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    bool a=false,b=false,c=false;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        cout << 1;
        a=true;
    }
    else cout << 0;
    if(a && s1[0]+s1[1]==s2[0]+s2[1]){
        cout << 1;
        b=true;
    }
    else cout << 0;
    char x=s1[2],y=s2[2];
    if(b && sc(x,y)){
        cout << 1;
        c=true;
    }
    else cout << 0;
    if(c && ling(x,y)){
        cout << 1;
    }
    else cout << 0;
    return 0;
}
