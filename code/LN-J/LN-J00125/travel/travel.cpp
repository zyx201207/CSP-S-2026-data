#include <bits/stdc++.h>
using namespace std;
string rc,xc,rz,xz;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> rc >> rz >> xc >> xz;
    int fl1=1,fl2=1,fl3=1,fl4=1;
    for(int i=0;i<2;i++){
        if(rc[i]!=xc[i]) fl1=0;
        if(rz[i]!=xz[i]) fl2=0;
    }
    if(rz[2]=='A'){
        if(xz[2]=='C') fl4=0;
        else if(xz[2]=='D' || xz[2]=='F'){
            fl3=0;
            fl4=0;
        }
    }
    else if(rz[2]=='B'){
        if(xz[2]=='D' || xz[2]=='F'){
            fl3=0;
            fl4=0;
        }
    }
    else if(rz[2]=='C'){
        if(xz[2]=='A') fl4=0;
        else if(xz[2]=='D' || xz[2]=='F'){
            fl3=0;
            fl4=0;
        }
    }
    else if(rz[2]=='D'){
        if(xz[2]=='A' || xz[2]=='B' || xz[2]=='C'){
            fl3=0;
            fl4=0;
        }
    }
    else if(rz[2]=='F'){
        if(xz[2]=='A' || xz[2]=='B' || xz[2]=='C'){
            fl3=0;
            fl4=0;
        }
    }
    if(fl1==0) cout << "0000";
    else if(fl2==0) cout << "1000";
    else if(fl3==0) cout << "1100";
    else if(fl4==0) cout << "1110";
    else cout << "1111";
    return 0;
}