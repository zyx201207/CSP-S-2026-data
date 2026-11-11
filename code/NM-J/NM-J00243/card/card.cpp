#include<bits/stdc++.h>
using namespace std;

int a[500010]

int main()
{
	freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n);
    for(int i = m ; i >= 1 ; i--)
    {
        cout << a[i] << " ";
    }
    return 0;
}
