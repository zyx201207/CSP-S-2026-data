#include <bits/stdc++.h>
using namespace std;
// void s(int a[10001], int n)
// {
//     int i = 0;
//     for(; i <= n-1; i++)
//     {
//     	if (i == n-1) break;
//     	if (a[i] > a[i+1])
// 		{
// 			int tmp = a[i];
// 			a[i] = a[i+1];
// 			a[i+1] = tmp; 
// 			i = -1;
// 		}	
// 	}
// }
int main()
{
    
    freopen("crystal.in", "r", read);
    freopen("crystal.out", "w", write);
    int n, m;
    
    cin >> n >> m;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans;
    int l = 0;
    long long sum;
    for(int r = 0; r < n; r++)
    {
        sum += a[r];
        while(a[r]*(r-l+1) - sum > m)
        {
            sum -= a[l];
            l++;
        }
        ans = max(ans, r-l+1);
    }
    cout << ans;
    return 0;
}
