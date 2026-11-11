#include<bits/stdc++.h>
using namespace std;

//vector <string> a;

string abc(int a)
{
    string s;
    while (a > 0)
    {
        char d = char(a%2);
        s = s + d;
        a /= 2;
    }
    return s;
}

string a[100005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        cin >> k;
    cout << k;
    return 0;
}
