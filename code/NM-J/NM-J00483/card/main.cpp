#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool a = 0,b = 0,c = 0,d = 0;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        a++;
    }else{
        cout << "0";
    }
    return 0;
}
