#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2,as;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        as+='1';
    }
    else{
        cout << "0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        as+='1';
    }
    else{
        cout << "1000";
        return 0;
    }
    bool a='A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C';
    bool b=s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D';
    if(a||b){
        as+='1';
    }
    else if(a == false&&b == false){
        cout << "1100";
        return 0;
    }
    if(b){
        cout << "1111";
        return 0;
    }
    if(a){
        if(s1[2]=='A'&&s1[2]=='C'||s1[2]=='C'&&s1[2]=='A'){
            cout << "1110";
            return 0;
        }
        else{
            cout << "1111";
        }
    }
    return 0;
}
