//柳奕曦 西安市含光中学 考号SN-S00498
//liuyixi xi an shi han guang zhong xue SN-S00498 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500110];
int pre[500110];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	//for(int i = 1; i <= n; i++) cout << a[i] << " ";

	for(int i = 1; i <= n; i++)
	{
		pre[i] = pre[i-1]+a[i];
			
	}
	//for(int i = 1; i <= n; i++) cout <<pre[i] << " ";
	int ans = 0;
	int killed =0;
	for(int i = 1; i <= n; i++)
	{
		//cout << "i:" << i << '\n';
		int sum= a[i]*(i-1-killed);
		int sum1 = sum-pre[i-1]+pre[killed];
		//cout << "sum:" << sum << "\n" << "sum1:" << sum1 << "\n";
		if(sum1 <= m)
		{
			ans++;
		}
		else
		{
			
			killed++;
			//ans--;
			//cout << "killed.\n" << killed<<'\n';
			
			sum= a[i]*(i-1-killed);
			int sum2 = sum-pre[i-1]+pre[killed];
			//cout << "sum:" << sum << '\n' << "sum2:"<<sum2<<'\n';
			if( sum2 >= sum1)
			{
				i--;
				continue;
			}
		}
		//cout << "\n =i=" << i << " " << "ans=" << ans <<"\n\n";
	}
	cout << ans;//313324
//	cout << a[313324]*313323-pre[313323] << "\n" << m << "\n";
//	cout << a[313325]*313324-pre[313324] << "\n" << m << "\n";
//	cout << a[315275]*315274-pre[315274] << "\n" << m;

//时间16:51，成功解决重复数字导致提前结束的问题，四个样例均正确
//纪念这个伟大的时刻！！！！！！ 
		return 0;
}

