#include <bits/stdc++.h>
using namespace std;
int main (){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string c[10];
    for(int i=1;i<=4;i++){
        cin >>c[i];
    }
    for(int i=1;i<=4;i++){
        if(c[i]!=c[i+2]) cout <<"0000";
        else cout <<"1111";
        break;
    }
    return 0;
}
