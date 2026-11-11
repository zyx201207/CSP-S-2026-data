#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a==c){
        cout << 1;
    }else{
        cout << "0000";
        return 0;
    }
    string s1=b.substr(0,2);
    string s2=d.substr(0,2);
    if(s1==s2){
        cout << 1;
    }else{
        cout << "000";
        return 0;
    }
    if(b[2]=='D'&&d[2]=='F'){
        cout << "11";
    }else if(b[2]=='F'&&d[2]=='D'){
        cout << "11";
    }else if(b[2]=='A'&&d[2]=='B'){
        cout << "11";
    }else if(b[2]=='B'&&d[2]=='C'){
        cout << "11";
    }else if(b[2]=='C'&&d[2]=='B'){
        cout << "11";
    }else if(b[2]=='B'&&d[2]=='A'){
        cout << "11";
    }else if(b[2]=='A'&&d[2]=='C'){
        cout << "10";
    }else if(b[2]=='C'&&d[2]=='A'){
        cout << "10";
    }else{
        cout << "00";
    }
    return 0;
}
