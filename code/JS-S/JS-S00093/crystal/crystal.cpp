#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],cnt = 1,id = 2,c[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    while(true)
    {
        if(m >= (a[id] - a[id - 1]) * (id - 1))
        {
            cnt++;
            m -= (a[id] - a[id - 1]) * (id - 1);
            id++;
        }
        else
        {
            cout << cnt;
            break;
        }
    }
    return 0;
}
/* *******  ***   **     *  *******  *     *        *          **     *     *     *   *       *         *****     *****                    *
      *      *    * *    *       *   *     *       * *         * *    *      *   *    *       *         *    *    *    *     *      *      *
      *      *    *  *   *      *    *     *      *   *        *  *   *       * *     *       *         *****     *****      *      *      *
      *      *    *   *  *     *     *******     *******       *   *  *        *      *       *         **        *        *****  *****    *
      *      *    *    * *    *      *     *    *       *      *    * *        *      *       *         * *       *          *      *      *
    * *      *    *     **   *       *     *   *         *     *     **        *       *     *          *  *      *          *      *
     **     ***   *      *  *******  *     *  *           *    *      *        *        *****           *   *     *                        *         */
