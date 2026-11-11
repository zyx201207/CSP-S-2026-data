#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;cin >> a >> b >> c >> d;
    string re="0000";
    if(a==c){
        re[0]='1';
    }
    if(re[0]=='1' && b[0]==d[0] && b[1]==d[1]){
        re[1]='1';
    }
    if(re[1]=='1' && ((b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C') || (b[2]>='D' && b[2]<='F' && d[2]>='D' && d[2]<='F'))){
        re[2]='1';
    }
    if(re[2]=='1' && ((int(b[2])+1==int(d[2])) || (int(d[2])+1==int(b[2])))){
        re[3]='1';
    }
    cout << re;



    return 0;
}
