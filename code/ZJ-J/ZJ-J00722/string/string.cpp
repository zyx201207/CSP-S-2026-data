#include <bits/stdc++.h>
using namespace std;
int n,a[200010],s[200010],i,j;
char b[200010];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>a[i]>>b[i];
	i = 1,j = n;
	while(i <= j)
	{
		if(b[i] != b[j])
			ans += min(a[i],a[j]);
		if(a[i] > a[j])
			a[i] -= a[j],j--;
		else if(a[j] > a[i])
			a[j] -= a[i],i++;
		else i++,j--;
	}
	cout<<ans;
	return 0;
}
