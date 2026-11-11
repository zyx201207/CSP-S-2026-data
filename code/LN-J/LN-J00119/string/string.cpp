#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        long long b;
        cin >> b;
        char a;
        cin >> a;
        for (int i = 0; i < b; i++)
            s += a;
    }
    long long len = s.size();
    if (len % 2 == 1)
    {
        long long mid = (len + 1) / 2;
        string A;
        A = s.substr(0, mid - 1);
        string B;
        B = s.substr(mid, len - 1);
        if (A == B)
        {
            cout << 0 << "\n";
            return 0;
        }
        else
        {
            long long j = len - 1;
            long long cnt = 0;
            for (long long i = 0; i < mid - 1; i++)
            {
                if (A[i] != B[j])
                    cnt++;
                j--;
            }
            cout << cnt << "\n";
        }
    }
    else
    {
        long long mid = len / 2 - 1;
        long long cnt1 = 0;
        if (s[mid] != s[mid + 1])
            cnt1 += 1;
        string A = s.substr(0, mid);
        string B = s.substr(mid + 2, len);
        long long j = len - 1;
        for (long long i = 0; i < mid; i++)
        {
            if (A[i] != B[i])
                cnt1++;
            j--;
        }
        mid = len / 2;
        long long cnt2 = 0;
        if (s[mid] != s[mid - 1])
            cnt2 += 1;
        string A2 = s.substr(0, mid - 1);
        string B2 = s.substr(mid + 1, len);
        j = len - 1;
        for (long long i = 0; i < mid; i++)
        {
            if (A2[i] != B2[i])
                cnt2++;
            j--;
        }
        cout << min(cnt1, cnt2) << "\n";
    }
    return 0;
}
