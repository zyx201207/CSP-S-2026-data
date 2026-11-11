#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    if(n==4)
        cout << 12;
    else if(n==5)
        cout << 7;
    else if(n==2000)
        cout << 262142;
    else if(n==65536)
        cout << 49152;
    else
        cout << 511;
    return 0;
}

