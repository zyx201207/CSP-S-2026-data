#include <bits/stdc++.h>

using namespace std;

namespace Solve
{
    vector<long long> arr;
    void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        freopen("crystal.in", "r", stdin);
        freopen("crystal.out", "w", stdout);
        long long n, m;
        cin >> n >> m;
        long long ans = 0;
        long long base = 0;
        long long tags = 0;
        for (long long i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
        for (long long i = 0; i < n; i++)
        {
            int flag = 0;
            for (long long j = 0; j < n; j++)
            {
                if(abs(arr[j]-arr[i]) < abs(arr[j] - base)){
                    flag++;
                }
            }
            if(flag > tags){
                base = arr[i];
                tags = flag;
            }
        }
        for(long long i = 0; i < n; i++){
            if(m >= abs(arr[i] - base)){
                m -= abs(arr[i] - base);
                ans++;
            }
        }
        cout << ans;
    }
}

int main()
{
    Solve::main();

    return 0;
}
