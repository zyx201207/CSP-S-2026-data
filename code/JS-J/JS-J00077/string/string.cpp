#include <bits/stdc++.h>
using namespace std;

long long n, sum;
long long a[200010];
char c[200010];
string str;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
        for(int j = 0;j < a[i];j++)
        {
            str += c[i];
        }
    }
    long long sizen = str.size();
    long long mid = ((sizen % 2) ? ((sizen+1) / 2) : (floor(sizen) / 2));
    for(int i = 0;i < mid;i++)
    {
        int j = sizen-1-i;
        sum += (str[i] != str[j]);
    }
    cout << sum << endl;
    return 0;
}