#include <iostream>
#include <cstring>
using namespace std;

string c1, c2;
string p1, p2;
int z1, z2;
char a1, a2;

bool ans1, ans2, ans3, ans4;

int main(){

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> p1 >> c2 >> p2;
    z1=(p1[0]-'0')*10+p1[1]-'0';
    z2=(p2[0]-'0')*10+p2[1]-'0';
    a1=p1[2]; a2=p2[2];

    ans1=(c1==c2);
    ans2=(ans1&&(z1==z2));
    if (!ans2) ans3=ans4=0;
    else {
        if (a1<a2) swap(a1, a2);
        if (a1=='F'&&a2=='D') {ans3=ans4=1;}
        else if (a1=='C'&&a2=='B') {ans3=ans4=1;}
        else if (a1=='B'&&a2=='A') {ans3=ans4=1;}
        else if (a1=='C'&&a2=='A') {ans3=1; ans4=0;}
        else {ans3=ans4=0;}
    }
    cout << ans1 << ans2 << ans3 << ans4 << endl;

    return 0;
}