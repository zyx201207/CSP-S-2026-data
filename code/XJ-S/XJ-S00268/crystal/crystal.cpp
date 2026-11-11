#include<bits/stdc++.h>
using namespace std;

long long int n,m,a[500005],b[500005],l = 1,r = 2,i,maxn = INT_MIN;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(i = 1;i <= n;i++) b[i] = b[i-1]+a[i];
	while(r <= n)
	{
		if(a[r]*(r-l) - (b[r-1]-b[l-1]) <= m)
		{
			if(r-l+1 > maxn) maxn = r-l+1;
			r++;
		}
		else l++;
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
