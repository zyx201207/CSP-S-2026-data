#include <bits/stdc++.h>
using namespace std;
vector <long long> A;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m;
    cin >> n >> m;
    for(long long i = 0;i < n;i++)
    {
        long long a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(),A.end(),greater <int>());
    long long x = A[0],ans = 1;
    for(long long i = 1;i < n;i++)
    {
        if(A[i] != A[i - 1] && ans < m)
        {
            x &= A[i];
            ans++;
        }
    }
    cout << x << endl;
    return 0;
}
