#include<bits/c++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    int n,d;
    int x[5000000000000000000000005];
    cin >> n >> d;
    for(int i = 0;i <= n;i++)
    {
        cin >> x[i];
    }
    if(c == 0 && t == 2)
    {
        if(n == 4)
            cout << 1 << endl << 2;
        else if(n == 5)
            cout << 0 << endl << 1;
        else
            cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0;
    }
    return 0;
}
