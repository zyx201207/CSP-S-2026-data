#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans,sum,minn = 0x3f,maxx = -0x3f,k,tmp,cc;
int main()
{
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        minn = min(minn,a[i]);
        maxx = max(maxx,a[i]);
    }
    tmp = (minn+maxx+1)/2;
    sort(a+1,a+n+1);
    k = upper_bound(a+1,a+n+1,tmp)-a-1;
    cc = a[k];
    for (int i = k;i >= 1;i--)
    {
    	//cout << i << " ";
    	if (m-(cc-a[k]))
		{
			m -= (cc-a[k]);
			cout << m << " ";
			continue;
		}
		break;
	}
	cout << sum;
    return 0;
}
