#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,m,a[600000],_sum_[600000],an = 1,_flag_ = 1;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
	{
		_sum_[i] = _sum_[i-1] + a[i];
		if(a[i] == a[i+1])_flag_++; 
		else 
		{
			if(_flag_ > an)an = _flag_;
			_flag_ = 1;
		}
	}
	for(int i=n;i>=2;i--)
	{
		if(_sum_[i-1] + m >= a[i] * (i - 1))
		{
			cout << i;
			return 0;
		}
	}
	cout << an;
	return 0;
}
