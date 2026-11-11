#include <iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    char a=s1[2],b=s2[2];
    bool a1,a2,a3,a4;
    a1=(c1==c2);
    a2=a1&&(s1[0]==s2[0])&&(s1[1]==s2[1]);
    a3=a2&&((s1[2]>'C')==(s2[2]>'C'));
    if(a3&&((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='C'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')||(a=='F'&&b=='D'))) a4=1;
    else a4=0;
    cout << a1 << a2 << a3 << a4;

    return 0;
}
