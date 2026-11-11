#include<bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cx>>sx>>cy>>sy;
    if(cx==cy) {
        cout<<1;
    }
    else {
        cout<<"0000";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(sx[0]==sy[0]&&sx[1]==sy[1]) {
        cout<<1;
    }
    else {
        cout<<"000";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(sx[2]<='C'&&sy[2]<='C') {
        cout<<1;
    }
    else if(sx[2]>='D'&&sy[2]>='D') {
        cout<<"11";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else {
        cout<<"00";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    int t=abs(sx[2]-sy[2]);
    if(t==1) {
        cout<<1;
    }
    else {
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
