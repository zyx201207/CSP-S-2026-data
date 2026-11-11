#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
int s[N];
string a,b;
vector<char>p,q;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    cin >> n;
    int res = 0;
    for (int i = 1;i <= n;i ++)
    {
        int s;
        char op;
        cin >> s >> op;
        for (int j = 1;j <= s;j ++)
        {
            q.push_back(op);
            p.push_back(op);
        }
    }
    reverse(q.begin(),q.end());
    long long sum = 0;
    for (int i = 0;i < q.size();i ++)
    {
        //cout << q[i] << ' ' << p[i] << endl;
        if (p[i] != q[i])
        {
            sum ++;
            //cout << 1 << endl;
        }
    }
    cout << sum / 2<< endl;
    return 0;
}
