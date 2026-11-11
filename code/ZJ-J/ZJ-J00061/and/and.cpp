#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005];

bool rule(unsigned long long a,unsigned long long b)
{
	if(a > b) return true;
	return false;
}

int main()
{
	//1.0s 1024MB
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	unsigned long long n = 0;
	unsigned long long m = 0;
	cin >> n;
	cin >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	
	sort(a,a+n,rule);
	
	unsigned long long ans = 0;
	for(int i = 0;i < m;i++)
	{
		if(i == 0){
			ans = a[i];
			continue;
		}
		ans = ans & a[i];
	}

	cout << ans;
	return 0;
}
