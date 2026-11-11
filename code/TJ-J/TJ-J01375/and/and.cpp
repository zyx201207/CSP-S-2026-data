#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>

using namespace std;

int n, num[200005], m;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    int i = 0, j = n - 2, cnt = num[n - 1];
    while(i < m - 1)
    {
        cout << cnt << " " << num[j] << endl;
        cnt = (cnt & num[j]);
        i++;  j--;
    }
    printf("%d", cnt);
    return 0;
}