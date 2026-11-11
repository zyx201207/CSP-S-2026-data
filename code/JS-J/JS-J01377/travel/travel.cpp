#include<bits/stdc++.h>
using namespace std;

int c,cc;
string s,ss;

bool f(){
    char a=s[2],b=ss[2];
    if(a!='D'&&a!='F'&&(b=='D'||b=='F')) return false;
    else if(b!='D'&&b!='F'&&(a=='D'||a=='F')) return false;
    return true;
}

bool judge(){
    char a=s[2],b=ss[2];
    if(a=='A'){
        if(b=='B') return true;
        return false;
    }
    if(a=='B'){
        if(b=='A'||b=='C') return true;
        return false;
    }
    if(a=='C'){
        if(b=='B') return true;
        return false;
    }
    if(a=='D'){
        if(b=='F') return true;
        return false;
    }
    if(a=='F'){
        if(b=='D') return true;
        return false;
    }
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c >> s >> cc >> ss;
    if(c==cc){
        cout << "1";
        if(s[0]==ss[0]&&s[1]==ss[1]){
            cout << "1";
            if(f()){
                cout << "1";
                if(judge()){
                    cout << "1";
                }
                else cout << "0";
            }
            else{
                cout << "00";
            }
        }
        else{
            cout << "000";
        }
    }
    else{
        cout << "0000";
    }
    return 0;
}
