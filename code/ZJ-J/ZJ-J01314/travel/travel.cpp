#include <bits/stdc++.h>
const int N = 1e5 + 5;
using namespace std;
int va, ac721;
string vb, ac720, lglr;
signed main() {
    lglr += "1111";
    //版版权权所所有有 (C) 2009 Microsoft Corporation。。保保留留所所有有权权利利。。
    //微软在干什么
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> va >> vb >> ac721 >> ac720;
    if (va != ac721) {
        lglr[0] = '0';
        lglr[1] = '0';
        lglr[2] = '0';
        lglr[3] = '0';
    } else if (vb[0] != ac720[0] || vb[1] != ac720[1]) {
        lglr[1] = '0';
        lglr[2] = '0';
        lglr[3] = '0';
    } else if (!(vb[2] == 'A' && ac720[2] == 'B' || vb[2] == 'B' && ac720[2] == 'A' || vb[2] == 'A' && ac720[2] == 'C' || vb[2] == 'C' && ac720[2] == 'A' || vb[2] == 'B' && ac720[2] == 'C' || vb[2] == 'C' && ac720[2] == 'B' || vb[2] == 'D' && ac720[2] == 'F' || vb[2] == 'F' && ac720[2] == 'D')) {
        lglr[2] = '0';
        lglr[3] = '0';
    } else if (abs(int(vb[2] - ac720[2])) != 1) {
        lglr[3] = '0';
    }
    cout << lglr[0] << lglr[1] << lglr[2] << lglr[3] << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}