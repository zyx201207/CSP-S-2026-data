#include "bits/stdc++.h"
using namespace std;
struct chaar
{
    int a;
    char b;
} s[200000];
int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);

    int n;

    cin >> n;

    for(int i = 1 ; i <= n ; i++) cin >> s[i].a >> s[i].b;

    int sum = 0;
    for(int i = 1 ; i < n ; i++)
    {
        if(s[i].b == s[i + 1].b) sum = 1;
    }
    if(sum == 1)
    {
        cout << "0";
        return 0;
    }
    else
    {
        cout << s[1].a;
        return 0;
    }

    return 0;
}
