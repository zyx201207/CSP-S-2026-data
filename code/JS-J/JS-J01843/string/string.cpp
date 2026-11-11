#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin >> a;
	for(int i=1;i<=a;i++)
	{
		int x;
		cin >> x;
		char t;
		cin >> t;
		while(x--)
		{
			s+=t;
		}
	}
	long long ans=0;
	for(int i=1;i<=a/2+1;i++){
		if(s[i]!=s[a-i])
		{
			ans++;
		}
	}	
	cout << ans;
	return 0;
}
