#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >>c2 >> s2;
    int a1=0,a2=0,a3=1,a4=0;
    if(c1 == c2) a1 = 1;
    if(a1==0){
        cout << "0000";
        return 0;
    }
    string p1="",p2="";
    p1 += s1[0]+s1[1];
    p2 += s2[0]+s2[1];
    char z1 = s1[2],z2 = s2[2];
    if(p1==p2) a2 = 1;
    if(a2==0){
        cout << a1 << "000";
        return 0;
    }
    if(a2 == 1){
        if(z1 == 'D' && z2 != 'F' || z1 == 'F' && z2 != 'D') a3 = 0;
        if(z1 == 'D' && z2 == 'C' || z1 == 'C' && z2 == 'D') a3 = 0;
        if(a3 == 1){
            if(z1-z2==1 || z2-z1==1) a4 = 1;
            if(z1 == 'D' && z2 == 'F' || z1 == 'F' && z2 == 'D') a4 = 1;
        }
    }
    cout << a1 << a2 << a3 << a4;
    return 0;
}
