#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //reopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    string x;
    if(a==c){
        if(b[0]+b[1]==d[0]+d[1]){
            if(((b[2]=='A' || b[2]=='B' || b[2]=='C') && (d[2]=='A' || d[2]=='B' || d[2]=='C')) || ((b[2]=='D' || b[2]=='F') && (d[2]=='D' || d[2]=='F'))){
                if((b[2]=='A' && d[2]=='B') || (b[2]=='B' && (d[2]=='A' || d[2]=='C')) || (b[2]=='C' && d[2]=='B') || (b[2]=='D' && d[2]=='F') || (b[2]=='F' || d[2]=='D')){
                    cout << 1111 << endl;
                }
                else{
                    cout << 1110 << endl;
                }
            }
            else{
                cout << 1100 << endl;
            }
        }
        else{
            cout << 1000 << endl;
        }
    }
    else{
        cout << "0000" << endl;
    }
    return 0;
}
