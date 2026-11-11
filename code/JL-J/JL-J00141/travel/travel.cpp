#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a != c){
        cout << "0000";
        return 0;
    }
    if(b[0] != d[0] || b[1] != d[1]){
        cout << 1000;
        return 0;
    }
    if((b[2] >= 'A' && b[2] <= 'C') && (d[2] == 'F' || d[2] == 'D')){
        cout << 1100;
        return 0;
    }
    if(b[2] + 1 == d[2] || b[2] - 1 == d[2]){
        cout << 1111;
        return 0;
    }
    else
        cout << 1110;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
