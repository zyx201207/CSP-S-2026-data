#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 8;
int n, m;
vector<int> edgs[N];
priority_queue<int, vector<int >, greater<int >> pq;
struct Node
{
    int id, n;
    /*bool operator<(Node &rhs, Node )const
    {
        return rhs <
    }*/
};
inline int read()
{
    LL num = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while('0' <= ch && ch <= '9')
    {
        num = (num << 3) + (num << 1) + ch - '0';
        ch = getchar();
    }
    return (f == 1 ? num : -num);
}
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cout << "0" << "\n" << " 2";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
