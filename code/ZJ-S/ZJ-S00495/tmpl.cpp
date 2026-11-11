#include <bits/stdc++.h>
using namespace std; bool _M_membg;
bool _M_memed; int main(){
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    double _M_use_mem = fabs(&_M_membg - &_M_memed) / 1024 / 1024;
    clog << _M_use_mem << "M" << endl;
    assert(_M_use_mem <= 256);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    return 0;
}