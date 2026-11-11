#include <bits/stdc++.h>
using namespace std;

//RX99
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r1,r2,k1,k2;
    cin >> r1 >> r2 >> k1 >> k2;
    cout << (r1==k1?"":"000") << ((r1==k1)?1000+((r2[0]==k2[0] and r2[1]==k2[1])?100+((((r2[2]-'A'-3)<0)==((k2[2]-'A'-3)<0))?10+(abs(r2[2]-k2[2])==1?1:0):0):0):0);
    return 0;
}
