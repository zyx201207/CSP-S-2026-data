

#include <bits/stdc++.h>
using namespace std;
vector<long long> ArrayMain;
long long dif[500050], difSum[500050], difSumSum[500050];
long long a1M, a1N, ans = 0;
#define ll long long
// 1, 2, 3, 4
// l = 1, r = 4, mid = **2**.
//
ll evaluation_1(int upval, int downval)
{
    ll cost = 0;
    for (int j = upval; j >= downval; j--)
    {
        cost += (ArrayMain[upval] - ArrayMain[j]);
    }
    return cost;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ArrayMain.resize(500050);
    cin >> a1M >> a1N;
    //cout << a1M << a1N << endl;
    bool flag = false;

    for (ll i = 1; i <= a1M; i++)
    {
        cin >> ArrayMain[i];
    }
    sort(ArrayMain.begin() + 1, ArrayMain.begin() + a1M + 1);
    int l = 1, r = a1M;
    //preprocess dif
    for (int i = 2; i <= a1M; i++)
    {
        dif[i] = ArrayMain[i] - ArrayMain[i-1];
    }
    while (l < r)
    {
		if (flag == true) break;
		ll cost = 0;
		int mid = (l + r) / 2;
		for (int j = mid; j >= 1; j--)
		{
			//cout << "cost:" << cost << ", k = " << k << ", j = " << j << endl;
			cost += (ArrayMain[mid] - ArrayMain[j]);
		}
		//cout << "mid: " << mid << ", cost:" << cost << endl;
		if (cost > a1N)
		{
		    r = mid; //cout << "r set to: " << mid << endl;
		}
		else
		{
		    l = mid; //cout << "l set to: " << mid << endl;
		}
		if (r - l == 1)
		{
			ll cost4 = 0;
			for (int j = r, k = 1; j >= 1; j--, k++)
			{
				cost4 += (ArrayMain[r] - ArrayMain[j]);
			}
			if (cost4 > a1N)
			    r = l;
			flag = true;
		}
	}
	while (ArrayMain[r+1] == ArrayMain[r])
		r++;
	//post-process: push r forward
    cout << r << endl;

    return 0;
}
// 1 2 4 8 9
//dif : 0, 1, 2, 4, 1
// cost:
// 0;
//1;
// 1 + 2 + 2;
// 1 + 2 + 2
//          + 2
// deprec
// 0 + 1;
//difSum: 0, 1, 3, 7, 8
// hypo: dif = 50, 49, 49, 49, 48
//h2: dif = 50, 60, 20, 20, 20, 20, 20
//dSS to 2: 1 ;
//
//dSS[3]: dSS[2] + dS[3] * (3-2);
// 1: 1 + 3
// 2:
// 1 * 2 + 3 * 1.
//difSumSum: 0, 1, 4, 11,
//n = 5
//possible: 0-> 3: 3, 1->3: 2.
//
//optimization
//0-1: 1.
//1 to 3
//3: 1. + 1 + 3.
//3 to 7?
//
// 1 2 4 8 9
//

