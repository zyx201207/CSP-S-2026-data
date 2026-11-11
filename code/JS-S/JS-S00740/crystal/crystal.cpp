//long long
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 5e5 + 100;

long long nums[MAXN] = {};
long long add[MAXN] = {};

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

    int n;
    int res = 0;
    long long m;

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> nums[i];
    }

    sort(nums + 1,nums + n + 1);

    /*
    for(int i = 1;i <= n;i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    */

    add[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        add[i] = add[i - 1] + nums[i];

        int l = 1,r = i;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            //cout << i << " " << mid << " " << nums[i] * (mid - 1) + add[i - mid] << " " << m + add[i - 1] << endl;
            if(nums[i] * (mid - 1) + add[i - mid] <= m + add[i - 1])
            {
                res = max(res,mid);
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }

    cout << res << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}

