#include <iostream>
using namespace std;

int C1,S1,C2,S2;
char SS1,SS2;

int f(int x) {
    return x>0?x:-x;
}

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> C1 >> S1 >> SS1 >> C2 >> S2 >> SS2;

    bool flag = C1==C2;
    cout << flag;

    flag &= S1==S2;
    cout << flag;

    flag &= (SS1=='A'||SS1=='B'||SS1=='C') && (SS2=='A'||SS2=='B'||SS2=='C') || (SS1=='D'||SS2=='F') && (SS2=='D'||SS2=='F');
    cout << flag;

    flag &= f(SS1-SS2) == 1;
    cout << flag;


    


    return 0;
}