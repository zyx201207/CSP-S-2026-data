#include<bits/stdc++.h>
using namespace std;
int n,m;
bool tp = 1;
long long a[200005],maxx,aand,m1[50],m2[50],num[50];
long long cf(int a){
	if(a == 0) return 1;
	return 2 * cf(a-1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){//输入+最大值特判 
		cin >> a[i];
		maxx = max(a[i],a[i-1]);
		if(i == 1) aand = a[i];
		else aand = aand & a[i];
		if(a[i] != (i-1)) tp == 0;
	}
	if(m == 1){//特判/易证：m=1时，最大的数就是题目所求
		cout << maxx;
		return 0;
	}
	if(m == 2){//m=2时有三个测试点，n都不大，可尝试暴力 
		long long x = 0;
		for(int i = 1;i < n;i++){
			for(int j = i + 1;j <= n;j++){
				long long yy = a[i] & a[j];
				x = max(x,yy);
			}
		}
		cout << x;
		return 0;
	}
	if(m == n){//特判m=n，只能全部 与 
		cout << aand;
		return 0; 
	}
	if(m == n - 1){//特判，可以依次遍历去掉哪个数后最大
		int p = a[2],maxp = 0;
		for(int i = 2;i <= n;i++) p = p & a[i];
		maxp = max(maxp,p);
		for(int i = 2;i <= n;i++){
			p = a[1];
			for(int j = 1;j < i;j++)
				p = p & a[i];
			for(int j = i + 1;j <= n;j++)
				p = p & a[i];
			maxp = max(maxp,p);
		}
		cout << maxp;
		return 0;
	}
	if(tp){//特判：数字递增 
		int nn = n,k2 = 0;
		while(nn){
			nn /= 2;
			k2++;
		}
		nn = n - 1;
		if(m >= cf(k2)) m = cf(k2);
		for(int i = 1;i <= m;i++) nn -= cf(i-1);
		cout << nn;
		return 0;
	}
	long long maxk = 0;
	for(int i = 1;i <= n;i++)
	{
		long long k = 1;
		while(a[i]){//统计每一位的1的数量
			if(a[i]%2 == 1){
				m1[k]++;
				m2[k] = m2[k] * 2 + 1;
			}
			else{
				m2[k] *= 2; 
			}
		}
		maxk = max(k,maxk);
	}
	if(m1[maxk]) num[maxk] = 1;
	for(int i = maxk - 1;i >= 1;i--)
	{
		int l = m1[i+1] & m1[i];//提取公共位
		int s = 0;//其中 1 的个数
		while(l){
			s += l % 2;
			l /= 2;
		}
		
	}
	int d = a[1] & a[2];
	cout << d;
	return 0;
}
