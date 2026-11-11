#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //
    string cx1,zw1,cx2,zw2;
    //
    cin >> cx1 >> zw1 >> cx2 >> zw2;
    //
    if(cx1!=cx2){
        cout << "0000";
        return 0;
    }
    if(zw1[1]!=zw2[1]){
        cout << "1000";
        return 0;
    }
    if(zw1[2]>='A' && zw1[2]<='C' && (zw2[2]=='D' || zw2[2]=='F') || zw2[2]>='A' && zw2[2]<='C' && (zw1[2]=='D' || zw1[2]=='F')){
        cout << "1100";
        return 0;
    }
    if(zw1[2]=='A' && zw2[2]=='C' || zw1[2]=='C' && zw2[2]=='A'){
        cout << "1110";
        return 0;
    }
    cout << "1111";
    //
    return 0;
}
