#include <bits/stdc++.h>
using namespace std;
vector <long long> B;
vector <long long> Bf;
vector <string> C;
string A = "";
string S = "";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    for(long long i = 0;i < n;i++)
    {
        long long a;
        string c;
        cin >> a >> c;
        B.push_back(a);
        Bf.push_back(a);
        C.push_back(c);
    }
    sort(B.begin(),B.end(),greater<int>());
    if(B[0] > 100000)
    {
        for(long long i = 0;i < n;i++)
        {
            A += C[i];
            S += C[i];
        }
        reverse(A.begin(),A.end());
        long long cnt = 0;
        if(A == S)
        {
            cout << 0 << endl;
            return 0;
        }
        for(long long i = 0;i < S.size();i++)
        {
            if(A[i] != S[i])
            {
                cnt++;
            }
        }
        cnt /= 2;
        cout << cnt * B[0] << endl;
    }
    else
    {
        for(long long i = 0;i < n;i++)
        {
            for(long long j = 0;j < Bf[i];j++)
            {
                A += C[i];
                S += C[i];
            }
        }
        reverse(A.begin(),A.end());
        long long cnt = 0;
        if(A == S)
        {
            cout << 0 << endl;
            return 0;
        }
        for(long long i = 0;i < S.size();i++)
        {
            if(A[i] != S[i])
            {
                cnt++;
            }
        }
        cnt /= 2;
        cout << cnt << endl;
    }
    return 0;
}
