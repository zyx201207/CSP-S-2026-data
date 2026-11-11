#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    string ans = "";
    bool p1 = false;
    if(a == c){
        ans+='1';
        p1 = true;
    }else{
        ans+='0';
    }
    bool po = false;
    if(p1&&(b[0] == d[0] && b[1] == d[1])){
        ans+='1';
        po = true;
    }else{
        ans+='0';
    }
    int b2 = b[2] - 'A' + 1;
    int d2 = d[2] - 'A' + 1;
    bool p2 = false;
    if(((b2 <= 3 && d2 <= 3) || (b2 > 3 && d2 > 3))&&po&&p1){
        ans+='1';
        p2 = true;
    }else{
        ans+='0';
    }
    int cha = abs(b2-d2);
    if(p2 && po && p1 && (!(b[2] == 'D' && d[2] == 'C') && !(b[2] == 'C' && d[2] == 'D')) && (cha == 1)){
            ans+='1';
    }else{
        ans+='0';
    }
    cout<<ans;
    return 0;
}
