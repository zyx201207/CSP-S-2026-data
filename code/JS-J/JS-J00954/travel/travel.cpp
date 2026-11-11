#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string s, ss;
string c, cc;

int main() {

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> c >> s >> cc >> ss;

    if(c == cc) 
        cout << 1;

    else {
        cout << "0000";
        return 0;
    }

    bool flag = true;
    for(int i = 0; i <= 1; ++i) {
        if(s[i] != ss[i]) {
            flag = false;
        }
    }
    if(flag)
        cout << 1;
    else  {
        cout << "000";
        return 0;
    }
    
    char pr = s[2];
    char px = ss[2];
    bool ok = ('C' >= pr && 'C' >= px) || ('D' <= pr && 'D' <= px);
    if(!flag){
        cout << "00";
        return 0;
    }
    else if(ok) 
        cout << 1;
    else{
        cout << "00";
        return 0;
    }

    if(!flag && !ok)
        cout << 0;
    else if(abs(pr - px) == 1)
        cout << 1;
    else cout << 0;
    return 0;
}