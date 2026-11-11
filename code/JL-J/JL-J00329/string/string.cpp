#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w", stdout);
    int n, d, c = 0;
    int a[n] = {0}, b{n} = {0};
    cin >> d;
    for(int i=0;i<=n; i++)
    {
        cin >> a[i] << b[i];
        cout << a[i] << " " << b[i] << endl;
    }
    for(int i=0;i<=n; i++)
    {
        if(a[i+1]!=a[i]&&i!=d-1)
        {
            c++;
        }
    }
    if(!c)
    {
        cout << o << endl;
    }
    return 0;
}
