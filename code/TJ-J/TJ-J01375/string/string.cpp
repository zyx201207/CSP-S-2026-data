#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>

using namespace std;

int n, cnt;
string str;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    int j;  char c;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c", &j, &c);
        while (j-- > 0)
        {
            str += c;
        }
    }
    int si = str.size();
    for (int i = 0; i <= si / 2; i++)
    {
        if (str[i] != str[si - i - 1]) cnt++;
    }
    printf("%d", cnt);
    return 0;
}