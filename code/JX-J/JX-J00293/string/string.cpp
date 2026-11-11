#include<bits/stdc++.h>
using namespace std;
string s[10000000];
struct zf
{
    int a;
    string c;
};
int w[1000000];
zf x[1000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int cnt = 0;
    cin >> n;
    if(n == 1)
        cout << "0";
    for(int i = 1;i <= n;i++)
    {
        cin >> x[i].a >> x[i].c;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= x[i].a;j++)
            s[i] = x[i].c;
    }
    for(int i = 0;i <= n;i++)
    {
        int l = 0;
        int r = n;
        if(s[l] != s[r])
        {
            cnt++;
            l++;
            r--;
        }
    }
    return 0;
}
