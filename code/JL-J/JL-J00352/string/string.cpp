#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	vector<long long> a(n);
	vector<char> s(n);
	for(int i = 0;i < n;i++)
	{
		cin>>a[i]>>s[i];
	}
	
	int L = 0, R = n - 1;
	long long ans = 0;
	
	while(L < R)
	{
		long long m = min(a[L],a[R]);
		
		if(s[L] != s[R])
			ans += m;
			
		a[L] -= m;
		a[R] -= m;
		
		if(a[L] == 0) L++;
		if(a[R] == 0) R--;
	}
	cout<<ans<<"\n";
	
	return 0;
}
