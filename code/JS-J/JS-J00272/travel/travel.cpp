#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
bool flag0, flag1, flag2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out","w", stdout);
    cin>>a>>b>>c>>d;
    if (a == c){
        cout<<1;
        flag0 = 1;
    }
    else {
        cout<<0;
        flag0 = 0;
    }
    if (b[0] == d[0] && b[1] == d[1] && flag0){
        cout<<1;
        flag1 = 1;
    }
    else {
        cout<<0;
        flag1 = 0;
    }
    if (((b[2]>='D' && d[2]>='D') || (b[2]<='C' && d[2]<='C')) && flag0 && flag1){
        cout<<1;
        flag2 = 1;
    }
    else {
        cout<<0;
        flag2 = 0;
    }
    if ((abs(b[2]-d[2]) == 1 || (b[2] == 'F' && d[2] == 'D') || (b[2] == 'D' && d[2] == 'F')) && flag0 && flag1 && flag2) cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
