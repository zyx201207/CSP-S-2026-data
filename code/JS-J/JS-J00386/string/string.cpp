#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.cpp","r","stdin");
    freopen("string.cpp","w","stdout");
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    string sa = "";
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        char y;
        cin >> x >> y;
        for(int j = 1;j <= x;j++)
        {
            sa += y;
        }
    }
    long long jsq = 0;
    for(int i = 0;i < sa.size() / 2;i++)
    {
        if(sa[i] != sa[sa.size() - i - 1])
        {
            jsq++;
        }
    }
    cout << jsq << endl;
    return 0;
}
