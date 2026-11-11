#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
bool f;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> a >> b >> c >> d;
    if(a==c){
        f=1;
        cout << 1;
    }else{
        f=0;
        cout << 0;
    }
    string t=b.substr(0,2),tt=d.substr(0,2);
    if(!f){
        cout << 0;
    }else if(t==tt){
        f=1;
        cout << 1;
    }else{
        f=0;
        cout << 0;
    }
    char pt=b[2],ptt=d[2];
    if(!f){
        cout << 0;
    }else if(pt<='C' && ptt<='C'){
        f=1;
        cout << 1;
    }else if(pt>'C' && ptt>'C'){
        f=1;
        cout << 1;
    }else{
        f=0;
        cout << 0;
    }
    //cout << abs(pt-ptt) << "\n";
    if(!f){
        cout << 0;
    }else if(abs(pt-ptt)==1){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}