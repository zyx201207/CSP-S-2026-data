#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r",stdin);
    freopen("string.out", "w",stdout);
    int n;
    cin >> n;
    string s = "";
    int a;
    string b;
    int sum = 0;
    for(int i = 0;i < n;i++)
    {
        cin >> a >> b;
        for(int i = 0;i < a;i++)
        {
            s += b;
        }
        sum += a;
    }
    int num = 0;
    for(int i = 0;i < sum / 2 + 1;i++)
    {
        if(s[i] != s[sum - 1 - i])
        {
            num++;
        }
    }
    cout << num;
    return 0;
}
