#include <iostream>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,cl,sl;
    cin >> c >> s >> cl >> sl;
    if(c==cl)cout << "1";
    else{
        cout << "0000";
        return 0;
    }

    if(s[0]==sl[0]&&s[1]==sl[1])cout << "1";
    else {
        cout << "000";
        return 0;
    }

    if(s[2]+sl[0]-2*'A' == 8)cout << "11";//DF
    else if(s[2]=='A'&&sl[2]=='C'||s[2]=='C'&&sl[2]=='A')cout << "10";//AC
    else if(s[2] + sl[2]=='A'+'B')cout << "11";//AB
    else if(s[2]=='B'&&sl[2]=='C'||s[2]=='C'&&sl[2]=='B')cout << "11";//BC
    else cout << "00";//no

    return 0;
}
