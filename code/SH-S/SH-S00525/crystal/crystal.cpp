/*
����һ�����飬���Խ���m�μ�һ��������󻯳��ִ�������Ԫ�صĳ��ִ���
���ǿ�����Ҫʹ�ö��ִ�
��ô���Ǿ���Ҫ֪��������һ�����ִ�������Ԫ�صĳ��ִ����������ܷ�ʵ������
ע�⵽�����е����ԣ���һ�����ִ����޷���ɣ���ô����ĳ��ִ���Ҳһ���޷����
��˿��Զ��ִ𰸡�
��ô���Ǿ���Ҫ���ǣ������е�����
1 2 4 8 9
ע�⵽���ִ�����˳���޹أ����ǿ��Կ���������
����Ҫ����������г��ִ�������Ԫ�س���x�Σ������С�Ĳ�������.����һ������ʱ�临�Ӷ����ߴ�ԼΪo(n) 
���ǿ��Գ���̰��ö�٣� 
����ÿ��ѡ��һ�����֣�����������Ҫ�󣡣�
��������ѡ���˵�Ԫ�ؿ�������ͬ��Ԫ�أ����Ǽ�Ϊk����ͬԪ��
��ô������Ҫ����޸Ĵ������ǣ���pre[x-k]����
������<m��������
��ʼʵ�ְɣ�������ʱ10���� 
5 2
1 1 1 -4 0 
' ' <<
3 1
0 -1 -1 
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int 
int pre[500005];
int a[500005];
	int n,m;
map<int,int> mp;

int check(int x)
{
	for (int i = 1;i <= n;i++)
	{
		// i want to let x ge element set to a[i];
		// there is already mp[a[i]] ge element
		// i just need to set the qian x-mp[a[i]] ge element into a[i];
		// it costs x-mp[a[i]]*a[i] - pre[x-mp[a[i]]];
		// panduan if it <= m
		if (a[i] == a[i-1]) continue;
		if (x <= mp[a[i]])
			return 1;
		int lastneed = x - mp[a[i]];	
		if (lastneed < i && lastneed*a[i] - (pre[i-1] - pre[i-lastneed-1]) <= m)
		{ 
//cout << x << ' ' << i << ' ' << lastneed <<' ' << (pre[i-1] - pre[lastneed-1]) << '\n';
			return 1;
		}
	}
	return 0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);

	for (int i = 1;i <= n;i++)
	{
		pre[i] = pre[i-1] + a[i];
	}
	int l = 0,r = n;
	int ans = 0;
	while (l <= r)
	{
		int mid = (l+r)/2;
		if (check(mid))
		{
			ans = mid;
			l = mid+1;
		}
		else
		{
			r = mid-1;
		}
	}
	cout << ans << '\n';
}
