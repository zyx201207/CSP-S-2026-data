#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    int m,n;
    cin >> m >> n;
    for (int a[i] ; i <= m;i++)
    {
        cin >> a[i];
        if (a[i] and a[i-1] == a[i])
        {
            cout << a[i] << endl;
        }
        else
        {
            cout << a[i-1] << endl;
        }
    }
    return 0;
}
//11 1111 110 110
