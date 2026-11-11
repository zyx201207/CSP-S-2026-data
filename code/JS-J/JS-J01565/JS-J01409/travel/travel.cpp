#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string s,t;
    cin>>a>>s>>b>>t;
    int ap = (s[0]-'0')*10+(s[1]-'0');
    int bp = (t[0]-'0')*10+(t[1]-'0');
    int az = s[2]-'A'+1;
    int bz = t[2]-'A'+1;
    if(a != b) cout<<"0000";
    else{
        cout<<"1";
        if(ap != bp) cout<<"000";
        else{
            cout<<"1";
            if(az <= 3 && bz <= 3){
                cout<<"1";
                if(abs(az-bz) == 1) cout<<"1";
                else cout<<"0";
            }
            else if(az >= 4 && bz >= 4) cout<<"11";
            else cout<<"00";
        }
    }
    return 0;
}
//8:45 kai xie
//8:50 tong guo suo you yang li
