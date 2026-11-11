#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,b;
    cin >> n >> b;
    for (int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    long long mid=n/2+1;
    cout << a[mid];
    return 0;
}
