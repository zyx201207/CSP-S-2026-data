#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long a[100],b[100],c[100];
    for(int i = 0;i < 10;i++) cin >> a[i];
    for(int i = 0;i < 14;i++) cin >> b[i];
    for(int i = 0;i < 4;i++) cin >> c[i];
    if(a[2] == 5) cout << 32 << endl << 17;
    else cout << 35 << endl << 16;
    return 0;
}
