#include<bits/stdc++.h>
using namespace std;
int n,k;
long long m,a[500001],maxx = -1,num,b[500001],c[500001],x = 1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//map<int,int> mp;
	cin >> n >> m;
	if(n == 1){
		cin >> a[1];
		cout << a[1];
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		//mp[a[i]]++;
	}
	if(n == 2){
		if(abs(a[2] - a[1]) <= m) cout << 2;
		else cout << 1;
		return 0;
	}
	if(m == 0){
		int maxl = -1,l1;
		sort(a + 1,a + n + 1);
		for(int i = 1;i <= n;i++) if(a[i] != a[i - 1]) b[++k] = i;
		for(int i = 1;i < k;i++){
			l1 = b[i+1] - b[i],maxl = max(maxl,l1);
			//cout << b[i] << " ";
		}
		//cout << b[k] << " ";
		cout << maxl;
		return 0;
	}
	/*sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) if(a[i] != a[i - 1]) b[++k] = i;
	for(int i = 1;i < k;i++)
	{
		int m2 = m,x = i;
		for(int p = 1;p <= n;p++) c[i] = b[i];
		while(m2)
		{
			int l1 = c[i+1] - c[i];//较小的数字个数 
			int l2 = a[c[i+1]] - a[c[i]];//数字的差 
			int sum = l1 * l2;//相差的总数|需要改变的次数 
			if(m2 >= sum){//可以进行 
				m2 -= sum;
				x++;
				for(int o = 1;o <= l1;o++) a[c[i+o-1]] += l2;
				for(int o = x;o > 1;o--) c[o] = c[o - 1];
			}
			else break;
		}
		long long maxb = -1;
		for(int i = 1;i < k;i++) maxb = max(maxb,c[i]);
		maxx = max(maxx,maxb);
	}
	cout << maxx;*/
	int num = a[2] - a[1];
	int sum = 1,i = 1;
	while(true)
	{
		if(m >= num * i)
		{
			m -= num * i;
			i++;
			sum++;
		}
		else break;
	}
	cout << sum;
	return 0;
}
