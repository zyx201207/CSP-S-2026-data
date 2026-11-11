#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,ans=0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int t;
		char c;
		cin >> t >> c;
		for(int j=0;j<t;j++)
		{
			s+=c;
		}
		cnt+=t;
	}
	
	string a=s.substr(0,cnt/2),b=s.substr(cnt/2+cnt%2,cnt/2);
	
	//cout << a << ' ' << b;
	int i=0,j=n-1; 
	
	while(i<n)
	{
		if(a[i]!=b[j])
		{
			ans++;
		}
		i++;
		j--; 
	}
	cout << ans;
	return 0;
}
