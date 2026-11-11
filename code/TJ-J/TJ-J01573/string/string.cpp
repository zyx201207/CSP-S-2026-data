#include<bits/stdc++.h>
using namespace std;
vector<char>q;
vector<char>m;
struct number
{
    char x;
    int y;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,c,sum = 0,cnt = 0;
    char b;
    cin >> a;
    number n[a + 10];
    for(int i = 1; i <= a; i++)
    {
        cin >> c >> b;
        n[i].y = c;
        sum += c;
        n[i].x = b;
        for(int j = 1; j <= c; j++)
        {
            q.push_back(b);
        }
    }
    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= n[i].y / 2; j++)
        {
            m.push_back(n[i].x);
        }
    }
    for(int i = 1; i <= sum / 2; i++)
    {
        if(q[i] != m[i])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
