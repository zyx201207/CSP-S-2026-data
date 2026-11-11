#include <bits/stdc++.h>
using namespace std;
long long n, len, ans;
struct Node
{
    long long a;
    char c;
};
vector<Node> _node(200005, {0, '\0'});
char at(long long idx)
{
    int curmaxidx = 0;
    for (int i = 1; i <= n; i++)
    {
        curmaxidx += _node[i].a;
        if (idx <= curmaxidx)
            return _node[i].c;
    }
    return '\0';
}
/*ostream& operator<<(ostream& os, Node nd)
{
    return os << "Node: {" << nd.a << ", " << nd.c << "}";
}*/
int main()
{
    freopen("string3.in", "r", stdin);
    freopen("string3.out", "w", stdout);
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> _node[i].a >> _node[i].c;
        len += _node[i].a;
    }
    /*//I have to BAO'LI'MEI'JV, even though O(n^2).
    for (long long i = 1; i < len / 2.0; i++)
    {
        if (at(i) != at(len-i+1))
            ans++;
    }*/
    for (int i = 1, j = n; i < j;)
    {
        if (_node[i].a < _node[j].a)
        {
            if (_node[i].c != _node[j].c)
                ans += _node[i].a;
            if (_node[i+1].a + _node[i].a > _node[j].a)
            {
                _node[i+1].a = _node[i+1].a + _node[i].a - _node[j].a;
                _node.insert(_node.begin() + i+1, {_node[j].a - _node[i].a, _node[i+1].c});
                j++;
                n++;
            }
            i++;
        }
        else if (_node[i].a == _node[j].a)
        {
            if (_node[i++].c != _node[j--].c)
                ans += _node[i].a;
        }
        else if (_node[i].a > _node[j].a)
        {
            if (_node[i].c != _node[j].c)
                ans += _node[j].a;
            if (_node[j-1].a + _node[j].a > _node[i].a)
            {
                _node[j-1].a = _node[j-1].a + _node[j].a - _node[i].a;
                _node.insert(_node.begin() + j-1, {_node[i].a - _node[j].a, _node[j-1].c});
                j++;
                n++;
            }
            j--;
        }
        /*cout << "-----Debug-----" << endl;
        for (int k = 1; k <= n; k++)
        {
            cout << "   " << "k is " << k << " " << _node[k];
            if (k == i)
                cout << "i";
            if (k == j)
                cout << "j";
            cout << endl;
        }
        cout << "   ans: " << ans << endl;
        cout << "---Debug-End---" << endl;*/
    }
    cout << ans;
    return 0;
}
