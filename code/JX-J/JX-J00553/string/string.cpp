#include<iostream>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
ll n,a[N],ra[N],l,r,sum,ans,lb,bl[N];
char c[N],rc[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	//int j = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		ra[n - i + 1] = a[i];
		rc[n - i + 1] = c[i];
		sum += a[i];
		//for(;j <= sum;j++) bl[j] = c[i];
	}
	//for(int i = 1;i <= n;i++) cout << ra[i] << rc[i] << endl;
	l = 1;
	r = 1;
	int li = 1,ri = 1;
	while(l <= sum || r <= sum)
	{
		ll ml = l + a[li];
		ll mr = r + ra[ri];
		if(ml < mr)
		{
			if(c[li] != rc[ri]) ans += ml - lb;
			l = ml;
			lb = l;
			li++;
		}
		else if(ml > mr)
		{
			if(c[li] != rc[ri]) ans += mr - lb;
			r = mr;
			lb = r;
			ri++;
		}
		else
		{
			if(c[li] != rc[ri]) ans += ml - lb;
			l = ml;
			li++;
			r = mr;
			ri++;
			lb = r;
		}
	}
	cout << ans / 2 << endl;
	/*ans = 0;
	for(int i = 1;i <= sum;i++)
	{
		if(bl[i] != bl[sum - i + 1]) ans++;
	}
	cout << ans / 2;*/
	return 0;
}
