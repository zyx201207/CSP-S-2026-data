#include <bits/stdc++.h>
using namespace std;
vector <long long>A;
vector <long long>C;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long c,t;
    cin >> c >> t;
    for(long long i = 0;i < t;i++)
    {
        long long n,d;
        cin >> n >> d;
        for(long long j = 0;j < n;j++)
        {
            long long a;
            cin >> a;
            A.push_back(a);
        }
        for(long long j = A.size() - 1;j >= 0;j--)
        {
            if(A[j] - A[j - 1] > d)
            {
                A.pop_back();
            }
        }
        if(A.size() - 3 > 0)
        {
            C.push_back(A.size() - 3);
        }
        else
        {
            C.push_back(0);
        }
        A.clear();
    }
    for(long long i = 0;i < t;i++)
    {
        cout << C[i] << endl;
    }
    return 0;
}
