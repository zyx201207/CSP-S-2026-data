#include<bits/stdc++.h>
using namespace std;

string sr1, sr2, sx1, sx2;
bool f;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> sr1 >> sr2 >> sx1 >> sx2;
    if(sr1==sx1) f = 1, cout << 1;
    else f = 0, cout << 0;
    if( f && (sr2[0] == sx2[0]) && (sr2[1] == sx2[1]) ) f = 1, cout << 1;
    else f = 0, cout << 0;
    if( f && ( (sr2[2]-'A'<3&&sx2[2]-'A'<3) || (sr2[2]-'A'>2&&sx2[2]-'A'>2) ) ) f = 1, cout << 1;
    else f = 0, cout << 0;
    if( f && ( (sr2[2]-sx2[2] != 2) && (sr2[2]-sx2[2] != -2) ) ) cout << 1;
    else cout << 0;
    return 0;
}
