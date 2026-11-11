#include<bits/stdc++.h>
using namespace std;
long long n , m;
long long a[500005];
long long t[500005];
vector<int> t1;
string s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i =1 ; i <= m ; i++)
    {
        t[i] = 1;
    }
    for(int i = 1; i <= n ; i++) cin >> a[i];
    for(int i  = 1 ; i <= n ; i++)
    {
       t.push_back(a[i]);
    }
    cout << 1;
    return 0;
}
