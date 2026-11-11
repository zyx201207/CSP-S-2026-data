#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
struct w
{
	long long ci,num,en;
}f[500005];
long long n,m;
long long crystal[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> crystal[i];
	}
	sort(crystal,crystal+n);
	f[0].ci  = 0;
	f[1].ci  = 1;
	f[1].num = crystal[1];
	f[0].num = 0;
	f[0].en  = m;
	f[1].en  = m;
	for(int i=2;i<=n;i++)
	{
		f[i].ci = f[i-1].ci ;
		f[i].num = f[i-1].num ;
		f[i].en = f[i-1].en ;
		if(f[i].en>=(crystal[i]-f[i-1].num)*f[i-1].ci)
		{
			f[i].ci = max(f[i].ci,f[i-1].ci+1);
			if(f[i].ci==f[i-1].ci+1)
				f[i].num = crystal[i];
				f[i].en -= (crystal[i]-f[i-1].num)*f[i-1].ci;
		}
	}
	cout << f[n].ci << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
