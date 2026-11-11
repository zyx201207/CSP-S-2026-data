#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        cout << 1;
        if(s1[1]==s2[1]&&s1[0]==s2[0]){
            cout << 1;
            char a=s2[2],b=s1[2];
            string s;
            s+=a;
            s+=b;
            //cout << s;
            if(s=="DF"||s=="FD"||s=="AB"||s=="AC"||s=="BA"||s=="BC"||s=="CA"||s=="CB"){
                cout << 1;
                if(s=="DF"||s=="FD"||s=="AB"||s=="BA"||s=="BC"||s=="CB"){
                    cout << 1;
                }
                else{
                    cout << 0;
                }
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
}//expect 100